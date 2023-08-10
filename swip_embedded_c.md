# Embedded System C Programming

### System Software

0. S/W & H/W 통합 Embedded System : Security, CPU, Memory, Performance, Signal Processing, AI Application, OS, Flash Management, Contactless, ...

1. System Call (S/W API) : Application - Operating System

2. ISA & Registers (H/W API) : Firmware - Hardware

3. S/W - H/W 구현 과정

    - S/W Development

        - Compiler : C language -> Assembly
        - Assembler : Assembly -> Object code

            > Compilation = Compiler + Assembler (per each Source)

        - Linker : Object files + Library header + ... -> Executable file

            > per each project(= executable file)

        - Debugging : Executable file -(Feedback by using breakpoint, ...)-> C Language

    - H/W Design

        - Synthesis : Verilog, VHDL -> Schematic
        - PnR : Schematic, Technical lib. -> Layout
        - CTS, STA, ... : Simulation (Verilog, Schematic, Layout)

### Compilation & Linking

0. Pre-processing : C -> Concatenated C code

    - Include header 파일, 각종 define, macro 등을 텍스트 변환/치환

        ```shell
        $ cpp hello_world.c hello_world.i
        ```

    - user-defined header를 포함하는 경우, 해당 header를 포함하는 경로를 컴파일러에 전달

        ```shell
        $ gcc -S hello_world.c -I {Header file path}
        ```

        ```c
        #include "./foo.h" // 상대경로로 참조
        ```

1. Compiler : C -> Object file (for each source)

    ```shell
    $ gcc -S hello_world.c
    $ as - o hello_world.o hello_world.s
    ```

2. Linker : Object files -> Executable file

    - Convert Object files to Executable file

        ```shell
        $ gcc -o hello_world hello_world.o
        ```

    - 소스 코드간 연결, 각 Source에 선언된 함수, 변수 등 객체 심볼을 연결해주는 역할
    - extern keyword : external linkage, 다른 Source 함수에서 해당 심볼을 가진 객체를 가져오겠다는 의미

        ```shell
        $ gcc -o hello_world hello_world.c hello_world2.c
        ```

3. Waived error/warning : 해당 error/warning을 무시하고 넘어감, 오류의 전후 상황 파악 필요

4. Native Compilation : 개발 환경과 실행 환경이 동일한 경우

    - x86 Intel 개발 환경에서 x86 Intel 보드에서 실행하는 경우(동일 실행파일 format : .exe)

5. Cross Compilation : 개발 환경과 실행 환경이 상이한 경우

    - x64 Intel 개발 환경에서 x64 ARM 보드에서 실행하는 경우 (다른 실행파일 : .hex)
    - tool-chain 통해 개발 필요

### C Programming

1. 80/20 법칙 : 20%의 코드가 전체 실행 시간의 80%를 차지 -> 'Hot spot'

2. Function in C : Black-box, Modular programming, ...

    - 함수 호출시 약속된 공간(Stack)에 인자를 집어넣고, 리턴값을 집어넣는 Copy Overhead 존재
    - OS상에서는 Context Switch라고 일반적으로 부름 : User <-> Kernel mode, ...

        > [Kernel mode](http://egloos.zum.com/rousalome/v/9984537)

3. Caller : 특정 함수를 호출하는 함수 vs Callee : 호출되는 함수

    ```c
    int factorial(int a) { // callee of main()
        return (a == 0) ? 1 : a * factorial(a - 1);
    }

    int main(void) { // caller of factorial()
        int result = factorial(10);
        return 0;
    }
    ```

4. Directive, Macro : text 치환/변환

    ```c
    #define MAX 255
    #define SQUARE(x) ((x) * (x))

    char arr[MAX];
    // char arr[255];

    int result = SQUARE(16 + 16);
    // int result = ((16 + 16) * (16 + 16));
    ```

5. Makefile format

    - Target : 빌드 대상이름, 일반적으로 최종 생성해내는 파일명

        > 복합 파일 빌드일때, 각각의 중간 Target에 대해서 Dependency 명시 필요

    - Dependencies : Target을 생성하기 위해 참조, 생성해내는 파일, 해당 파일을 우선적으로 생성
    - Recipe : 빌드 명령어 모음, Tab 필수(Indent; 들여쓰기)

        ```make
        <Target> : <Dependencies>
            <Recipe>
        ```

    - Reserved

        0. Use : $(VAR_NAME)
        1. CC: 컴파일러
        2. CFLAGS: 컴파일 옵션
        3. OBJS: 중간 산물 Object 파일 목록
        4. TARGET: 빌드 대상(실행 파일) 이름
        5. LDFLAGS: 링커 옵션
        6. LDLIBS: 링크 라이브러리

        ```make
        CC=gcc
        CFLAGS=-g -Wall
        OBJS=main.o foo.o bar.o
        TARGET=app.out

        $(TARGET): $(OBJS)
            $(CC) -o $@ $(OBJS)

        main.o: foo.h bar.h main.c
        foo.o: foo.h foo.c
        bar.o: bar.h bar.c
        ```

    - make clean, install : 의존성으로 인한 이전 파일 존재 제거, 필요 라이브러리 copy 등 환경 설정

        ```make
        clean:
            rm -f *.o
            rm -f $(TARGET)

        install:
            sudo apt-get install gcc
        ```

    - comment : '#'

6. ECO : Engineering Changing Order(설계 변경)

7. **Instruction Set Architecture(ISA)** : target architecture에 맞는 명령어 셋

8. Little Endian : LSB - Low Addr. <-> Big Endian : LSB - High Addr.

    - Little Endian : Intel x86, TriCore, ...
    - Big Endian : Arm, Motorola, ...

### Processor Structure

1. AP vs MCU

    - AP : Operating System이 Process Scheduling 담당

        > H/W - Firmware - OS - Application Process

    - MCU : Firmware가 자체적으로 고려

        > H/W - Firmware (+ Application) : Bus Connected(CPU, Memory, I/O) <-> Peripherals

2. Bus-Interconnected Blocks : On-Board vs On-Chip

    - Processor, I/O Interface, Ethernet 등은 하나의 Bus로 연결됨

        > ARM은 속도에 따라 분류(AMBA 2.0 기준) : AHB(ARM High-Performance Bus), APB(Advanced Peripheral Bus)

    - 최근은 SoC로 On-Chip Bus로 칩 내에 모든 Block들이 한번에 통합되는 경향

    - High-Bandwidth Memory의 등장으로 대량의 데이터가 처리 가능해짐 : AI 효율 증가

3. Dedicated Harness vs Bus Interconnected

    - Dedicated Harness : 속도 빠름, 확장이 어려움(커넥터 기하급수적으로 증가)

    - Bus-Interconnected : 속도 느림(정의된 Protocol로 접근 필요 ; Bus Idle 필요), 확장성 좋음

        > Arbitration, Acknowledge, CRC/AC, Bus Idle 등 다양한 기법을 통해 신뢰성 증가 필요

4. Embedded MCU-Based System

    - Processor : CPU
    - Memory: ROM(Read-Only Memory), RAM(Random Access Memory ; SRAM)
    - Peripheral

        1. Sensing : ADC(Analog Digital Convertor)
        2. Counter/Timer : to drive PWM, Driver, LED, other Controller
        3. Communication : Serial Port(UART), SPI, I2C, CAN, LIN

            > Debug Port(JTAG), Automotive(CAN, LIN), ...

5. CPU Internal(Very Fast) - (Cache Mem.) - External(Slow) Bus Connection

    - Program Counter(Reg.) : 실행할 Inst. 메모리 위치, Addr. Bus
    - Inst Reg., Inst decoder, Timing, Control : Control Bus
    - ALU, Register : Data Bus

6. Interrupt-based Program Execution

    - 프로그램을 실행 중 Interrupt를 던져 Exception 수행
    - Interrupt 발생시 user mode에서 FIQ, IRQ, System, Supervisor 등(ARM 기준) 으로 Context-Switching 발생(Overhead 발생 가능 ; Register 등 현재 상태를 따로 Save 해야함)

        > 일부 모드의 경우(FIQ, ...) Register를 Save/Backup이 필요없이 전환 가능

    - <-> Pooling-Based Program Execution : if-statement 등 제어문을 지속적으로 지나는 실행 방식

7. Interrupt

    - Main Program 실행
    - IRQ(Interrupt Request)

        > External(센서, ...) vs Internal(내부 타이머, 통신, 예외, ...) Interrupt 존재

    - 현재 상태 저장 (Context-Switch 시작)
    - Interrupt Vector Table에서 해당하는 Interrupt 종류의 주소로 Jump : IVT

        > Reset, Supervisor Call, IRQ, FIQ, ...

    - Interrupt 동작 수행
    - 특정 요청 Masking(우선순위 밑의 interrupt 무시)

        > 우선순위가 높은 Interrupt의 경우 추가 Interrupt 동작 : Nested

    - Interrupt 동작이 끝난 뒤, 저장한 상태로 복원
        > SPSR ; Saved Program State Register -> CPSR ; Current ~

---

## 22.06.02

### Variable, Address, Memory Allocation

1. Basic data types : C is Typed Language

    1. Character Type

        - char, unsigned char : 1byte

    2. Integer Type : Fixed-Point Type

        - short int, unsigned short int : 2byte (machine dependent)

            > short, unsigned short

        - int, unsigned int : 4byte (machine dependent)

        - long int (= long), unsigned long int (= unsigned long) : 4byte

        - long long int, unsigned long long int : 8byte

            > long long, unsigned long long

    3. Floating Point Variable : cannot use equal comparison

        - float : 4byte

        - double : 8byte

        - long double : 16byte

    4. Void : cannot use Variable Type (only can use void\*, return type)

        - void : 1byte

        - void\* : 4byte / 8byte (machine independent)

        - Cannot convert void\* to other pointer(need explicit casting) in C++

            > [LINK](https://github.com/ComMang/Hyundai_SWIP_Projects/blob/main/SWIP_CPP_Programming.md#explicit-casting-in-c)

    5. Pointer : TYPE\*

        - Different for reference operator & in C++

        - void\*, int\*, double\*, USER_DEFINED_TYPE\*, ... : 4 / 8byte (x86 / x64 environment)

        - can be referred by pointer operator \*

    6. Reference (C++) : TYPE&

        > [LINK](https://github.com/ComMang/Hyundai_SWIP_Projects/blob/main/SWIP_CPP_Programming.md#reference-type)

        - Alias of referred variable

        - should initialize by lvalue

            > rvalue reference(TYPE&&), const reference(const TYPE&) can refer rvalue

        - int&, double&, float&, ... : 4 / 8byte (x86 / x64 environment)

2. (Addition) Memory mapped I/O : memory(register)의 특정 영역에 I/O pin 동작이 묶여있음, ex) General Purpose I/O, ...

    - <-> Part mapped I/O

3. Global/Local Object

    1. (Global) Function : **Decay**로 인해 함수명은 함수 호출시 처음 시작되는 주소를 가르킴

    2. Array : **Decay**로 인해 배열명은 배열 첫 요소의 주소를 가르킴

    3. Global/Local Variable : 프로그램 전체 / 함수 생성-소멸의 Scope를 가짐

        1. Local Static/Auto Object : 프로그램 내에서 더이상 사용하지 않을때 소멸됨
        2. Global Static/Extern Object : Internal/External Linkage

            > Extern은 memory allocation이 발생하지 않음 : External linkage인 심볼을 연결함

4. Structure : struct keyword

    - Alignment : 구조체 내부에서 가장 큰 크기를 가진 type을 할당 단위로

    - 비어있는 부분은 padded 영역으로 사용하지 않음

    - ex) char[20], char[10], int = 20 + 10 + **2**(padding byte) + 4 = 36Byte

### Micro Processor(= uP) System

1. Central Processing Unit : uP

    - Program Counter
    - Stack Counter
    - Instruction Register
    - Accumulator, Operand, ... Register
    - Flag(= State) Register

2. Memory : Code, Instruction, Data(Stack, Heap, Constant, ..)

    > 하버드 Arch. (Inst. / Data Mem.) vs 폰 노이만 Arch. (Inst. + Data)

    - Volatile : DRAM, SRAM, Register(= Flip-Flop)

    - Non-Volatile(Programmable ROM) : SSD, Flash, EEPROM

    - Memory Profile : TEXT - DATA - BSS - HEAP <-> STACK

        1. TEXT : Code
        2. BSS : Global Variable
        3. DATA : Constant, String, ...
        4. HEAP : Dynamic Memory Allocation
        5. STACK : Local Variable
            - 메모리 용량이 부족하면, heap과 stack 영역이 Overlap될 가능성 존재

3. I/O & Peripherals Devices

4. Bus-based Communication

    - Address bus : for memory access

    - Control bus : for decode instruction, R/W Memory, ...

    - Data bus : for transfer Data to I/O Device, CPU, ...

    - Direct Memory Access(DMA) : CPU가 개입하지 않고, Block간 통신 

### Instruction Set Architecture : H/W API

1. ISA에 정의된 Inst.를 이용해 Register에 값을 쓰면, H/W 동작이 바뀜

2. Register를 읽으면, H/W 상태 파악 가능

---

## 22.06.03

### Interrupt-Driven Program

1. Interrupt Service Routine (ISR) : Interrupt Vector Table (IVT)에 호출 주소 정의됨 

2. Program Status Word : 비교 연산에 따른 조건 비트(Overflow, Equal, ...), 우선순위, kernel 모드, 각종 제어 비트 등을 포함

3. Interrupt의 한종류로 Exception 존재 : Error Handling 관련

    1. Invalid Instruction : Instruction Fetch이후 정의되지 않은 명령어인지 확인한 경우 Exception 발생
    2. Divide by 0
    3. Invalid Memory Access : 프로그램에 할당된 메모리 이외를 접근하려고 할 때, Exception 발생

4. User mode에서 발생 가능한 Interrupt는 Exception이 아님

    - Timer Interrupt, Program Finished, External Source, ...