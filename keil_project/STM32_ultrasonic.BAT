SET PATH=C:\Keil_v5\ARM\ARMCC\Bin;C:\ProgramData\Oracle\Java\javapath;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\RVCT_EAT\Programs\3.1\569\win_32-pentium;C:\Program Files\TortoiseSVN\bin;C:\Program Files\Microsoft\Web Platform Installer\;C:\Program Files (x86)\Microsoft ASP.NET\ASP.NET Web Pages\v1.0\;C:\Program Files (x86)\Windows Kits\8.0\Windows Performance Toolkit\;C:\Program Files\Microsoft SQL Server\110\Tools\Binn\;C:\Program Files (x86)\Microchip\xc32\v1.40\bin;C:\Program Files\Git\cmd;C:\Program Files (x86)\Microchip\xc8\v1.38\bin;C:\Program Files (x86)\Microchip\xc16\v1.26\bin;C:\Program Files (x86)\Microchip\xc32\v1.42\bin;C:\Program Files\CMake\bin;C:\Program Files\Java\jdk1.8.0_91;C:\Program Files (x86)\SSH Communications Security\SSH Secure Shell;D:\opencv\build\x64\vc11\bin;D:\opencv\build\x86\vc11\bin
SET CPU_TYPE=STM32F103C8
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=STM32_ultrasonic
SET CPU_CLOCK=0x00B71B00
"C:\Keil_v5\ARM\ARMCC\Bin\ArmAsm" --Via ".\output\stm32f10x._ia"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\gpio.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\main.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\nvic.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\ram.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\timer.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\uart.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\ultrasonic.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\stm32f10x_gpio.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\stm32f10x_i2c.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\stm32f10x_rcc.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\stm32f10x_flash.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\system_stm32f10x.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\stm32f10x_usart.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\stm32f10x_it.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\misc.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmLink" --Via ".\output\STM32_ultrasonic.lnp"
"C:\Keil_v5\ARM\ARMCC\Bin\fromelf.exe" ".\output\STM32_ultrasonic.axf" --i32combined --output ".\output\STM32_ultrasonic.hex"
