# subst

 `subst` is a command line program which parses `printf` format strings and replaces substrings surrounding the '%' format specifiers with short unique keys to reduce the overall length of the string. The replaced substring is stored in a JSON map which is written to standard output and can be used to [reconstruct the originally intended output at runtime](https://github.ecodesamsung.com/agnel-kurian/minicom-subst2).

## Overview

 C programs use [printf style format strings](https://man7.org/linux/man-pages/man3/fprintf.3.html#DESCRIPTION) to format output. For example:
 
 ```
 void log_progress(float bps, int transferred, const char *remaining) {
   printf("Bytes per second: %f, Bytes transferred: %d, Time remaining: %s\n",
     bps, transferred, remaining);
 }
 ```
 
 In the printf statement above, if the format specifier (the first argument) was shortened, it would lead to a reduction in binary size which can be considerable for binaries with a large number of such format strings. One approach to do this is by replacing the substrings surrounding the % specifiers with short keys. The original substring is placed in a lookup table against the short key. At runtime the originally intended output string can be reconstructed by looking up the keys in the table.
 
Using the previous example, the `printf` call can be replaced with the following:
 
```
 void log_progress(float bps, int transferred, const char *remaining) {
   printf("<A>%f<B>%d<C>%s\n",
     bps, transferred, remaining);
 }
 ```

The corresponding lookup table (as JSON) would be:
 ```
 {
   "<A>": "Bytes per second: ",
   "<B>": ", Bytes transferred: ",
   "<C>": ", Time remaining: "
 }
 ```
 
> [!NOTE]
> The keys are enclosed in `<` and `>` to distinguish them from values of the variables. If (say) the value of some variable contained an "A", then when parsing the output, the "A" would be interpreted as a short key... enclosing with some delimiters reduces the chance for confusion)

By parsing the output at runtime we can [intercept the short keys and dynamically reconstruct the output](https://github.ecodesamsung.com/agnel-kurian/minicom-subst2) as originally intended. For example assuming these values for the arguments:
```
bps: 2048
transferred: 10000
remaining: 5 minutes
```

The binary would produce:
```
<A>2048<B>10000<C>5 minutes
```
 
Using the lookup table we can reconstruct the original message:
```
Bytes per second: 2048, Bytes transferred: 10000, Time remaining: 5 minutes
```

## Implementation

> [!NOTE]
> The regular expression `%[-#0 +'I]?[*0-9]?(\.[*0-9]*)?(hh|[hlqLjzt]|ll)?[diouxXeEfFgGaAcsCSpnm]` used below was constructed based on inputs from the [printf man pages](https://man7.org/linux/man-pages/man3/fprintf.3.html#DESCRIPTION)

### 1. Locating printf format strings

The following `grep` call is used to select `printf` format strings in the code base.

```
grep -rnE --exclude-dir=external --exclude-dir=tools --exclude-dir=build --exclude-dir=docs --exclude-dir=lib
  --exclude-dir=resource --include=\*.c --include=\*.cc --include=\*.cpp --include=\*.C 
  '".*%[-#0 +'\''I]?[*0-9]?(\.[*0-9]*)?(hh|[hlqLjzt]|ll)?[diouxXeEfFgGaAcsCSpnm].*"' *
```

The command lists matching lines in the below form, which is passed as standard input to `subst`.
```
<file-name>:<line-no>:<line>
```

Example output:
```
apps/shell/tash_pm.c:58:            shdbg("pm_domain_register failed(%d)\n", get_errno());
apps/shell/tash_pm.c:72:        shdbg("First open pm driver using tash_pm_open_driver() to timedsuspend %s domain\n", TASH_PM_DOMAIN_NAME);
apps/shell/tash_pm.c:74:        shdbg("Unable to timedsuspend the %s domain for %d ms, error = %d\n", TASH_PM_DOMAIN_NAME, milliseconds, get_errno());
```
    
### 2. Extracting substrings surrounding % format specifiers

 - `subst` (this project) parses the file name, line number and matching line from standard input
 - `boost::regex` is used to extract format strings matching `"[^"]*%[^"]*"`
 - For each format string we look for embedded % specifiers using `%[-#0 +'I]?[*0-9]?(\.[*0-9]*)?(hh|[hlqLjzt]|ll)?[diouxXeEfFgGaAcsCSpnm]`
 - The substrings surrounding the format specifiers are extracted, and inserted into a map against an auto-generated sequential integer key (formatted as [base64](https://en.wikipedia.org/wiki/Base64) to reduce length).
 - The keys are written in place of the extracted substrings using `sed -i`
 - The generated map is written to standard output as JSON.

### 3. Dynamically reconstructing output at runtime

For demonstration, a [fork](https://github.ecodesamsung.com/agnel-kurian/minicom-subst2) of [minicom](https://en.wikipedia.org/wiki/Minicom) has been created to parse the binary output and dynamically replace the short keys with the original text using the generated JSON look-up table.

> [!NOTE]
> Build requires a boost_1_82_0 in the same directory as CMakeLists.txt

## Invocation

### Manual

First build and install this package:

```
  cd <location>/subst
  mkdir build
  cd build
  cmake --install-prefix <install-path>
  cmake --build .
  cmake --install .

```

Add the install location to the PATH variable and execute the subst tool:
```
 export PATH=<install-path>:$PATH

 grep -rnE --exclude-dir=external --exclude-dir=tools --exclude-dir=build --exclude-dir=docs 
   --exclude-dir=lib --exclude-dir=resource --include=\*.c --include=\*.cc --include=\*.cpp --include=\*.C 
   '".*%[-#0 +'\''I]?[*0-9]*(\.[*0-9]*)?(hh|[hlqLjzt]|ll)?[diouxXeEfFgGaAcsCSpnm].*"' * | grep -vE ':\s*(\<[fs]printf)' | subst > ~/str-map.json 
```
This is a sample invocation on the TizenRT code base. (`printf` and variants are excluded for reasons not related to this discussion.) The generated look-up table is saved to a JSON file which will be used later to re-construct the output from the binaries.

### Integrate with Makefile.unix

WIP

TODO
====

 - Stash changes before build but retain it in working area (both tracked, untracked and ignored files)
 - This requires git stash -a to include untracked and ignored files
 - Update Makefile.unix to invoke subst
 - Report size reduction post build
 - Undo all changes from subst after build (or commit as separate branch)
 - Restore stashed changes post build
 - Report location of .json and how to invoke custom minicom tool


