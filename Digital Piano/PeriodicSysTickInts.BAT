SET PATH=C:\Keil\ARM\BIN40;C:\Program Files (x86)\HP SimplePass 2012\x64;C:\Program Files (x86)\HP SimplePass 2012\;;C:\Program Files (x86)\AMD APP\bin\x86_64;C:\Program Files (x86)\AMD APP\bin\x86;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files (x86)\ATI Technologies\ATI.ACE\Core-Static;C:\Program Files (x86)\Hewlett-Packard\HP SimplePass Identity Protection\x64;C:\Program Files (x86)\Calibre2\;C:\Program Files (x86)\PharosSystems\Core;C:\Program Files\Calibre2\;C:\Program Files (x86)\QuickTime\QTSystem\
SET ARMCC41INC=C:\Keil\ARM\RV31\Inc
SET ARMCC41LIB=C:\Keil\ARM\RV31\Lib
SET CPU_TYPE=LM3S1968
SET CPU_VENDOR=Luminary Micro
SET UV2_TARGET=PeriodicSysTickInts
SET CPU_CLOCK=0x007A1200
"C:\Keil\ARM\BIN40\ArmAsm" --Via ".\hex&bin\startup._ia"
"C:\Keil\ARM\BIN40\ArmCC" --Via ".\hex&bin\dac.__i"
"C:\Keil\ARM\BIN40\ArmCC" --Via ".\hex&bin\pll.__i"
"C:\Keil\ARM\BIN40\ArmCC" --Via ".\hex&bin\sound.__i"
"C:\Keil\ARM\BIN40\ArmCC" --Via ".\hex&bin\piano.__i"
"C:\Keil\ARM\BIN40\ArmCC" --Via ".\hex&bin\test.__i"
"C:\Keil\ARM\BIN40\ArmCC" --Via ".\hex&bin\main.__i"
"C:\Keil\ARM\BIN40\ArmLink" --Via ".\Hex&Bin\Main.lnp"
C:\Keil\ARM\BIN40\fromelf.exe ".\Hex&Bin\Main.axf" --i32combined --output ".\Hex&Bin\Main.hex"
c:\Keil\ARM\BIN40\fromelf.exe --bin .\Hex&Bin\PeriodicSysTickInts.axf --output .\Hex&Bin\ PeriodicSysTickInts.bin
