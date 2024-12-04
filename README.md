# Media2WinCOFF
Convert any file to PE/COFF format for Windows OS.

![Media2WinCOFFdiagram](https://github.com/user-attachments/assets/cde21357-978e-4c5f-9637-b28566976842)

# Purpose
I need this custom tool for my projects. Because i need to embed a readonly files into the executables for Windows Platforms. <br>
Since llvm-objcopy only provide ELF, HEX, and BINARY format only. So, i need to make my own for Windows environment that use different binary format such as PE/COFF.

# Usage
```
Media2WinCOFF.exe <filename, ....>
```

# Technologies
- Windows API
- Windows PE/COFF Format
