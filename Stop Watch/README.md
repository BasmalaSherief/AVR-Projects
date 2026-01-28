# Stop Watch System

## Project Description
A digital Stop Watch implemented using the ATmega32 microcontroller. The system counts time in **Hours:Minutes:Seconds** format and displays it on six multiplexed 7-segment displays.

## Features
- **Time Counting**: Accurately counts seconds, minutes, and hours using Timer1 in CTC mode.
- **Display**: Six 7-segment displays driven by a multiplexing technique to save I/O pins.
- **Microcontroller**: ATmega32 running at 1MHz (default).

## Controls
The system is controlled via external interrupts:

| Function | Input | Interrupt | Trigger Edge | Description |
| :--- | :--- | :--- | :--- | :--- |
| **Reset** | `PD2` | `INT0` | Falling Edge | Resets the time (hh:mm:ss) to 00:00:00. |
| **Pause** | `PD3` | `INT1` | Rising Edge | Pauses the stop watch by disabling the timer clock. |
| **Resume** | `PB2` | `INT2` | Falling Edge | Resumes the stop watch by enabling the timer clock. |

## Technical Implementation
- **Timer1**: Configured in CTC (Clear Timer on Compare Match) mode with a prescaler of 1024 to generate an interrupt every 1 second ($F_{CPU} = 1MHz$).
    - `OCR1A` = 1000 approx. (Logic: $T_{timer} = \frac{1024}{10^6} \to 1s \approx 1000 \text{ cycles}$? Actually $F_{timer} = 10^6/1024 \approx 976 Hz$. To get 1 sec interrupt, OCR1A should be close to 976. The code uses 1000, which gives $\approx 1.024$ seconds).
- **Interrupts**:
    - `INT0`, `INT1`, `INT2` used for control logic.
    - `TIMER1_COMPA` used for time counting logic.
- **GPIO**:
    - `PORTC` (Lower 4 bits): Connected to the 7447 decoder inputs (A, B, C, D) for the 7-segment displays.
    - `PORTA` (Lower 6 bits): Connected to the enable/common pins of the 6 displays for multiplexing.
