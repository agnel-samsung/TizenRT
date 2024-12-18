# Test Results

## 1. Debugging features disabled; no substitution

```

File: app1_dbg
There are 18 section headers, starting at offset 0x1735c:

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .text             PROGBITS        0e45b030 00b030 0000d8 00  AX  0   0  4
  [ 2] .rodata           PROGBITS        0e45b108 00b108 0000a1 01 AMS  0   0  1
  [ 3] .data             PROGBITS        60280000 010000 000004 00  WA  0   0  1
  [ 4] .bss              NOBITS          60280004 010004 00001c 00  WA  0   0  1
  [ 5] .comment          PROGBITS        00000000 010004 000049 01  MS  0   0  1
  [ 6] .ARM.attributes   ARM_ATTRIBUTES  00000000 01004d 000039 00      0   0  1
  [ 7] .debug_abbrev     PROGBITS        00000000 010086 000231 00      0   0  1
  [ 8] .debug_info       PROGBITS        00000000 0102b7 000661 00      0   0  1
  [ 9] .debug_line       PROGBITS        00000000 010918 0002b0 00      0   0  1
  [10] .debug_aranges    PROGBITS        00000000 010bc8 000038 00      0   0  1
  [11] .debug_loc        PROGBITS        00000000 010c00 0000ac 00      0   0  1
  [12] .debug_ranges     PROGBITS        00000000 010cac 000028 00      0   0  1
  [13] .debug_str        PROGBITS        00000000 010cd4 000446 01  MS  0   0  1
  [14] .debug_frame      PROGBITS        00000000 01111c 000030 00      0   0  4
  [15] .symtab           SYMTAB          00000000 01114c 002d40 10     16  21  4
  [16] .strtab           STRTAB          00000000 013e8c 00341c 00      0   0  1
  [17] .shstrtab         STRTAB          00000000 0172a8 0000b3 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings), I (info),
  L (link order), O (extra OS processing required), G (group), T (TLS),
  C (compressed), x (unknown), o (OS specific), E (exclude),
  D (mbind), y (purecode), p (processor specific)

File: common_dbg
There are 21 section headers, starting at offset 0x132198:

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .text             PROGBITS        0e163010 003010 0178ac 00  AX  0   0  8
  [ 2] .ARM.extab        PROGBITS        0e17a8bc 01a8bc 000108 00   A  0   0  4
  [ 3] .ARM.exidx        ARM_EXIDX       0e17a9c4 01a9c4 0001d0 00  AL  1   0  4
  [ 4] .rodata           PROGBITS        0e17ab98 01ab98 005d18 00   A  0   0  8
  [ 5] .ctors            INIT_ARRAY      0e1808b0 0208b0 000008 04  WA  0   0  4
  [ 6] .data             PROGBITS        60780000 030000 00015a 00  WA  0   0  4
  [ 7] .bss              NOBITS          6078015c 03015c 000a04 00  WA  0   0  4
  [ 8] .comment          PROGBITS        00000000 03015a 000049 01  MS  0   0  1
  [ 9] .ARM.attributes   ARM_ATTRIBUTES  00000000 0301a3 000037 00      0   0  1
  [10] .debug_abbrev     PROGBITS        00000000 0301da 016980 00      0   0  1
  [11] .debug_info       PROGBITS        00000000 046b5a 07a515 00      0   0  1
  [12] .debug_line       PROGBITS        00000000 0c106f 0274b8 00      0   0  1
  [13] .debug_aranges    PROGBITS        00000000 0e8528 002878 00      0   0  8
  [14] .debug_str        PROGBITS        00000000 0eada0 00b5ea 01  MS  0   0  1
  [15] .debug_loc        PROGBITS        00000000 0f638a 0217bc 00      0   0  1
  [16] .debug_ranges     PROGBITS        00000000 117b46 003910 00      0   0  1
  [17] .debug_frame      PROGBITS        00000000 11b458 00693c 00      0   0  4
  [18] .symtab           SYMTAB          00000000 121d94 00adb0 10     19 2077  4
  [19] .strtab           STRTAB          00000000 12cb44 005582 00      0   0  1
  [20] .shstrtab         STRTAB          00000000 1320c6 0000d0 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings), I (info),
  L (link order), O (extra OS processing required), G (group), T (TLS),
  C (compressed), x (unknown), o (OS specific), E (exclude),
  D (mbind), y (purecode), p (processor specific)

File: tinyara.axf
There are 25 section headers, starting at offset 0x6e866c:

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .xip_image2.text  PROGBITS        0e000020 010020 07ff50 00  AX  0   0  8
  [ 2] .rodata           PROGBITS        0e07ff70 08ff70 020582 00   A  0   0 16
  [ 3] .code             PROGBITS        60100000 0c0000 002000 00  AX  0   0 256
  [ 4] .ARM.exidx        ARM_EXIDX       0e0a04f4 0b04f4 000008 00  AL  1   0  4
  [ 5] .fini_array       NOBITS          0e0a04fc 0b04fc 000b04 04  WA  0   0  1
  [ 6] .data             PROGBITS        60102000 0c2000 000eac 00  WA  0   0 64
  [ 7] .bss              NOBITS          60102ec0 0c2eac 0143d0 00  WA  0   0 64
  [ 8] .heap             NOBITS          60117290 0c2eac 002000 00  WA  0   0  1
  [ 9] .stack            NOBITS          60119300 0c2eac 000800 00  WA  0   0 256
  [10] .psram_heap.start PROGBITS        60119b00 0de933 000000 00   W  0   0  1
  [11] .bluetooth_t[...] PROGBITS        c8800000 0d0000 00e933 00   A  0   0  4
  [12] .ARM.attributes   ARM_ATTRIBUTES  00000000 0de933 000035 00      0   0  1
  [13] .debug_line       PROGBITS        00000000 0de968 0d9e66 00      0   0  1
  [14] .debug_info       PROGBITS        00000000 1b87ce 3169ad 00      0   0  1
  [15] .debug_abbrev     PROGBITS        00000000 4cf17b 06fe83 00      0   0  1
  [16] .debug_aranges    PROGBITS        00000000 53f000 00c690 00      0   0  8
  [17] .debug_str        PROGBITS        00000000 54b690 03cc36 01  MS  0   0  1
  [18] .debug_ranges     PROGBITS        00000000 5882c6 013350 00      0   0  1
  [19] .comment          PROGBITS        00000000 59b616 000076 01  MS  0   0  1
  [20] .debug_frame      PROGBITS        00000000 59b68c 01c90c 00      0   0  4
  [21] .debug_loc        PROGBITS        00000000 5b7f98 0c9341 00      0   0  1
  [22] .symtab           SYMTAB          00000000 6812dc 045c10 10     23 13012  4
  [23] .strtab           STRTAB          00000000 6c6eec 021670 00      0   0  1
  [24] .shstrtab         STRTAB          00000000 6e855c 000110 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings), I (info),
  L (link order), O (extra OS processing required), G (group), T (TLS),
  C (compressed), x (unknown), o (OS specific), E (exclude),
  D (mbind), y (purecode), p (processor specific)

```

## 2. All debugging features and logs enabled; no substitution

```


File: app1_dbg
There are 18 section headers, starting at offset 0x17644:

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .text             PROGBITS        0e45b030 00b030 0000d8 00  AX  0   0  4
  [ 2] .rodata           PROGBITS        0e45b108 00b108 0000a9 01 AMS  0   0  1
  [ 3] .data             PROGBITS        60280000 010000 000004 00  WA  0   0  1
  [ 4] .bss              NOBITS          60280004 010004 00001c 00  WA  0   0  1
  [ 5] .comment          PROGBITS        00000000 010004 000049 01  MS  0   0  1
  [ 6] .ARM.attributes   ARM_ATTRIBUTES  00000000 01004d 000039 00      0   0  1
  [ 7] .debug_abbrev     PROGBITS        00000000 010086 000231 00      0   0  1
  [ 8] .debug_info       PROGBITS        00000000 0102b7 000661 00      0   0  1
  [ 9] .debug_line       PROGBITS        00000000 010918 0002a9 00      0   0  1
  [10] .debug_aranges    PROGBITS        00000000 010bc1 000038 00      0   0  1
  [11] .debug_loc        PROGBITS        00000000 010bf9 0000ac 00      0   0  1
  [12] .debug_ranges     PROGBITS        00000000 010ca5 000028 00      0   0  1
  [13] .debug_str        PROGBITS        00000000 010ccd 00045f 01  MS  0   0  1
  [14] .debug_frame      PROGBITS        00000000 01112c 000030 00      0   0  4
  [15] .symtab           SYMTAB          00000000 01115c 002ea0 10     16  21  4
  [16] .strtab           STRTAB          00000000 013ffc 003592 00      0   0  1
  [17] .shstrtab         STRTAB          00000000 01758e 0000b3 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings), I (info),
  L (link order), O (extra OS processing required), G (group), T (TLS),
  C (compressed), x (unknown), o (OS specific), E (exclude),
  D (mbind), y (purecode), p (processor specific)

File: common_dbg
There are 21 section headers, starting at offset 0x13c930:

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .text             PROGBITS        0e163010 003010 0187f4 00  AX  0   0  8
  [ 2] .ARM.extab        PROGBITS        0e17b804 01b804 000108 00   A  0   0  4
  [ 3] .ARM.exidx        ARM_EXIDX       0e17b90c 01b90c 0001d0 00  AL  1   0  4
  [ 4] .rodata           PROGBITS        0e17bae0 01bae0 0073be 00   A  0   0  8
  [ 5] .ctors            INIT_ARRAY      0e182ea0 022ea0 000008 04  WA  0   0  4
  [ 6] .data             PROGBITS        60780000 030000 00015e 00  WA  0   0  4
  [ 7] .bss              NOBITS          60780160 030160 000a00 00  WA  0   0  4
  [ 8] .comment          PROGBITS        00000000 03015e 000049 01  MS  0   0  1
  [ 9] .ARM.attributes   ARM_ATTRIBUTES  00000000 0301a7 000037 00      0   0  1
  [10] .debug_abbrev     PROGBITS        00000000 0301de 017b26 00      0   0  1
  [11] .debug_info       PROGBITS        00000000 047d04 07feab 00      0   0  1
  [12] .debug_line       PROGBITS        00000000 0c7baf 028b78 00      0   0  1
  [13] .debug_aranges    PROGBITS        00000000 0f0728 002a18 00      0   0  8
  [14] .debug_str        PROGBITS        00000000 0f3140 00ba3f 01  MS  0   0  1
  [15] .debug_loc        PROGBITS        00000000 0feb7f 0228cf 00      0   0  1
  [16] .debug_ranges     PROGBITS        00000000 12144e 0035d8 00      0   0  1
  [17] .debug_frame      PROGBITS        00000000 124a28 006d84 00      0   0  4
  [18] .symtab           SYMTAB          00000000 12b7ac 00b8d0 10     19 2233  4
  [19] .strtab           STRTAB          00000000 13707c 0057e4 00      0   0  1
  [20] .shstrtab         STRTAB          00000000 13c860 0000d0 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings), I (info),
  L (link order), O (extra OS processing required), G (group), T (TLS),
  C (compressed), x (unknown), o (OS specific), E (exclude),
  D (mbind), y (purecode), p (processor specific)

File: tinyara.axf
There are 25 section headers, starting at offset 0x73beac:

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .xip_image2.text  PROGBITS        0e000020 010020 08a4b0 00  AX  0   0  8
  [ 2] .rodata           PROGBITS        0e08a4d0 09a4d0 02df3a 00   A  0   0 16
  [ 3] .code             PROGBITS        60100000 0d0000 002000 00  AX  0   0 256
  [ 4] .ARM.exidx        ARM_EXIDX       0e0b840c 0c840c 000008 00  AL  1   0  4
  [ 5] .fini_array       NOBITS          0e0b8414 0c8414 000bec 04  WA  0   0  1
  [ 6] .data             PROGBITS        60102000 0d2000 00112c 00  WA  0   0 64
  [ 7] .bss              NOBITS          60103140 0d312c 015efc 00  WA  0   0 64
  [ 8] .heap             NOBITS          6011903c 0d312c 002000 00  WA  0   0  1
  [ 9] .stack            NOBITS          6011b100 0d312c 000800 00  WA  0   0 256
  [10] .psram_heap.start PROGBITS        6011b900 0ee933 000000 00   W  0   0  1
  [11] .bluetooth_t[...] PROGBITS        c8800000 0e0000 00e933 00   A  0   0  4
  [12] .ARM.attributes   ARM_ATTRIBUTES  00000000 0ee933 000035 00      0   0  1
  [13] .debug_line       PROGBITS        00000000 0ee968 0e50a6 00      0   0  1
  [14] .debug_info       PROGBITS        00000000 1d3a0e 33d250 00      0   0  1
  [15] .debug_abbrev     PROGBITS        00000000 510c5e 072fe3 00      0   0  1
  [16] .debug_aranges    PROGBITS        00000000 583c48 00c940 00      0   0  8
  [17] .debug_str        PROGBITS        00000000 590588 03d54d 01  MS  0   0  1
  [18] .debug_ranges     PROGBITS        00000000 5cdad5 0135c0 00      0   0  1
  [19] .comment          PROGBITS        00000000 5e1095 000076 01  MS  0   0  1
  [20] .debug_frame      PROGBITS        00000000 5e110c 01d958 00      0   0  4
  [21] .debug_loc        PROGBITS        00000000 5fea64 0ce288 00      0   0  1
  [22] .symtab           SYMTAB          00000000 6cccec 04d2e0 10     23 14872  4
  [23] .strtab           STRTAB          00000000 719fcc 021dcf 00      0   0  1
  [24] .shstrtab         STRTAB          00000000 73bd9b 000110 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings), I (info),
  L (link order), O (extra OS processing required), G (group), T (TLS),
  C (compressed), x (unknown), o (OS specific), E (exclude),
  D (mbind), y (purecode), p (processor specific)

```


## 3. All debugging features and logs enabled; with substitution

```



File: app1_dbg
There are 18 section headers, starting at offset 0x17644:

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .text             PROGBITS        0e45b030 00b030 0000d8 00  AX  0   0  4
  [ 2] .rodata           PROGBITS        0e45b108 00b108 0000a1 01 AMS  0   0  1
  [ 3] .data             PROGBITS        60280000 010000 000004 00  WA  0   0  1
  [ 4] .bss              NOBITS          60280004 010004 00001c 00  WA  0   0  1
  [ 5] .comment          PROGBITS        00000000 010004 000049 01  MS  0   0  1
  [ 6] .ARM.attributes   ARM_ATTRIBUTES  00000000 01004d 000039 00      0   0  1
  [ 7] .debug_abbrev     PROGBITS        00000000 010086 000231 00      0   0  1
  [ 8] .debug_info       PROGBITS        00000000 0102b7 000661 00      0   0  1
  [ 9] .debug_line       PROGBITS        00000000 010918 0002a9 00      0   0  1
  [10] .debug_aranges    PROGBITS        00000000 010bc1 000038 00      0   0  1
  [11] .debug_loc        PROGBITS        00000000 010bf9 0000ac 00      0   0  1
  [12] .debug_ranges     PROGBITS        00000000 010ca5 000028 00      0   0  1
  [13] .debug_str        PROGBITS        00000000 010ccd 00045f 01  MS  0   0  1
  [14] .debug_frame      PROGBITS        00000000 01112c 000030 00      0   0  4
  [15] .symtab           SYMTAB          00000000 01115c 002ea0 10     16  21  4
  [16] .strtab           STRTAB          00000000 013ffc 003592 00      0   0  1
  [17] .shstrtab         STRTAB          00000000 01758e 0000b3 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings), I (info),
  L (link order), O (extra OS processing required), G (group), T (TLS),
  C (compressed), x (unknown), o (OS specific), E (exclude),
  D (mbind), y (purecode), p (processor specific)

File: common_dbg
There are 21 section headers, starting at offset 0x13c940:

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .text             PROGBITS        0e163010 003010 0187f4 00  AX  0   0  8
  [ 2] .ARM.extab        PROGBITS        0e17b804 01b804 000108 00   A  0   0  4
  [ 3] .ARM.exidx        ARM_EXIDX       0e17b90c 01b90c 0001d0 00  AL  1   0  4
  [ 4] .rodata           PROGBITS        0e17bae0 01bae0 0069ce 00   A  0   0  8
  [ 5] .ctors            INIT_ARRAY      0e1824b0 0224b0 000008 04  WA  0   0  4
  [ 6] .data             PROGBITS        60780000 030000 00015e 00  WA  0   0  4
  [ 7] .bss              NOBITS          60780160 030160 000a00 00  WA  0   0  4
  [ 8] .comment          PROGBITS        00000000 03015e 000049 01  MS  0   0  1
  [ 9] .ARM.attributes   ARM_ATTRIBUTES  00000000 0301a7 000037 00      0   0  1
  [10] .debug_abbrev     PROGBITS        00000000 0301de 017b26 00      0   0  1
  [11] .debug_info       PROGBITS        00000000 047d04 07feab 00      0   0  1
  [12] .debug_line       PROGBITS        00000000 0c7baf 028b78 00      0   0  1
  [13] .debug_aranges    PROGBITS        00000000 0f0728 002a18 00      0   0  8
  [14] .debug_str        PROGBITS        00000000 0f3140 00ba3f 01  MS  0   0  1
  [15] .debug_loc        PROGBITS        00000000 0feb7f 0228cf 00      0   0  1
  [16] .debug_ranges     PROGBITS        00000000 12144e 0035d8 00      0   0  1
  [17] .debug_frame      PROGBITS        00000000 124a28 006d84 00      0   0  4
  [18] .symtab           SYMTAB          00000000 12b7ac 00b8e0 10     19 2234  4
  [19] .strtab           STRTAB          00000000 13708c 0057e4 00      0   0  1
  [20] .shstrtab         STRTAB          00000000 13c870 0000d0 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings), I (info),
  L (link order), O (extra OS processing required), G (group), T (TLS),
  C (compressed), x (unknown), o (OS specific), E (exclude),
  D (mbind), y (purecode), p (processor specific)

File: tinyara.axf
There are 25 section headers, starting at offset 0x73be94:

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .xip_image2.text  PROGBITS        0e000020 010020 08a4b0 00  AX  0   0  8
  [ 2] .rodata           PROGBITS        0e08a4d0 09a4d0 029b64 00   A  0   0 16
  [ 3] .code             PROGBITS        60100000 0d0000 002000 00  AX  0   0 256
  [ 4] .ARM.exidx        ARM_EXIDX       0e0b4034 0c4034 000008 00  AL  1   0  4
  [ 5] .fini_array       NOBITS          0e0b403c 0c403c 000fc4 04  WA  0   0  1
  [ 6] .data             PROGBITS        60102000 0d2000 00112c 00  WA  0   0 64
  [ 7] .bss              NOBITS          60103140 0d312c 015efc 00  WA  0   0 64
  [ 8] .heap             NOBITS          6011903c 0d312c 002000 00  WA  0   0  1
  [ 9] .stack            NOBITS          6011b100 0d312c 000800 00  WA  0   0 256
  [10] .psram_heap.start PROGBITS        6011b900 0ee933 000000 00   W  0   0  1
  [11] .bluetooth_t[...] PROGBITS        c8800000 0e0000 00e933 00   A  0   0  4
  [12] .ARM.attributes   ARM_ATTRIBUTES  00000000 0ee933 000035 00      0   0  1
  [13] .debug_line       PROGBITS        00000000 0ee968 0e5091 00      0   0  1
  [14] .debug_info       PROGBITS        00000000 1d39f9 33d250 00      0   0  1
  [15] .debug_abbrev     PROGBITS        00000000 510c49 072fe3 00      0   0  1
  [16] .debug_aranges    PROGBITS        00000000 583c30 00c940 00      0   0  8
  [17] .debug_str        PROGBITS        00000000 590570 03d54d 01  MS  0   0  1
  [18] .debug_ranges     PROGBITS        00000000 5cdabd 0135c0 00      0   0  1
  [19] .comment          PROGBITS        00000000 5e107d 000076 01  MS  0   0  1
  [20] .debug_frame      PROGBITS        00000000 5e10f4 01d958 00      0   0  4
  [21] .debug_loc        PROGBITS        00000000 5fea4c 0ce288 00      0   0  1
  [22] .symtab           SYMTAB          00000000 6cccd4 04d2e0 10     23 14872  4
  [23] .strtab           STRTAB          00000000 719fb4 021dcf 00      0   0  1
  [24] .shstrtab         STRTAB          00000000 73bd83 000110 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings), I (info),
  L (link order), O (extra OS processing required), G (group), T (TLS),
  C (compressed), x (unknown), o (OS specific), E (exclude),
  D (mbind), y (purecode), p (processor specific)

```




