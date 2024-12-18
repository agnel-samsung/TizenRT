
```
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al

## 1. Debugging features disabled; no substitution
File: app1_dbg
  [ 2] .rodata           PROGBITS        0e45b108 00b108 0000a1 01 AMS  0   0  1
File: common_dbg
  [ 4] .rodata           PROGBITS        0e17ab98 01ab98 005d18 00   A  0   0  8
File: tinyara.axf
  [ 2] .rodata           PROGBITS        0e07ff70 08ff70 020582 00   A  0   0 16
## 2. All debugging features and logs enabled; no substitution
File: app1_dbg
  [ 2] .rodata           PROGBITS        0e45b108 00b108 0000a9 01 AMS  0   0  1
File: common_dbg
  [ 4] .rodata           PROGBITS        0e17bae0 01bae0 0073be 00   A  0   0  8
File: tinyara.axf
  [ 2] .rodata           PROGBITS        0e08a4d0 09a4d0 02df3a 00   A  0   0 16
## 3. All debugging features and logs enabled; with substitution
File: app1_dbg
  [ 2] .rodata           PROGBITS        0e45b108 00b108 0000a1 01 AMS  0   0  1
File: common_dbg
  [ 4] .rodata           PROGBITS        0e17bae0 01bae0 0069ce 00   A  0   0  8
File: tinyara.axf
  [ 2] .rodata           PROGBITS        0e08a4d0 09a4d0 029b64 00   A  0   0 16

test@Jammy:~/subst/tests$ node -p 's1 = 0x2df3a; s2 = 0x29b64; (s1 - s2) / s1'
0.0922653518792039
test@Jammy:~/subst/tests$ node -p 's1 = 0x0073be; s2 = 0x0069ce; (s1 - s2) / s1'
0.08585892676341546
test@Jammy:~/subst/tests$ # above delta after subst
test@Jammy:~/subst/tests$ # for tiny and common resp
test@Jammy:~/subst/tests$ node -p 's1 = 0x02df3a; s2 = 0x020582; (s1 - s2) / s1'
0.2961247064574058
test@Jammy:~/subst/tests$ node -p 's1 = 0x0073be; s2 = 0x005d18; (s1 - s2) / s1'
0.195680053999325
test@Jammy:~/subst/tests$ 
test@Jammy:~/subst/tests$ # above delta b/w full logs and no logs (no substitution, log reduction/hashing)log
test@Jammy:~/subst/tests$

```




