## Display
The final stage of our heart rate monitor project involved translating the analog ECG signal into a digital format and presenting it on a visual display. To accomplish this, we employed an ATmega328p microcontroller. This microcontroller served as the bridge between the analog world of our ECG signal and the digital realm of data processing.

Given the ATmega328p's input range limitation of 0V to 5V, a re-scaling of our ECG output was necessary. To achieve this, we designed a dedicated circuit and PCB that accurately converted the amplified ECG signal to fit within the ATmega328p's operating range.
![Offset Circuit](https://github.com/RavinduMPK/Heart-Monitor/assets/68577937/92de2a78-e26d-4f39-bfb3-a24628bbed8c)


Once the hardware was in place, we proceeded to code the ATmega328p microcontroller. The code was responsible for interfacing with the analog-to-digital converter (ADC) of the microcontroller, reading the re-scaled ECG signal, and then driving the visual display. Through careful coding and calibration, we ensured that the digital representation of the ECG waveform accurately mirrored the heart's electrical activity.
![Display Circuit](https://github.com/RavinduMPK/Heart-Monitor/assets/68577937/79300532-c6f8-4ab6-9442-b58e2a5620c8)


In essence, this final phase of the project brought together hardware design, analog-to-digital conversion, microcontroller programming, and display output. The result was a user-friendly display that showcased the heart rate monitor's output in a clear and informative manner, making it accessible and valuable for medical professionals and patients alike.

![Display PCB](https://github.com/RavinduMPK/Heart-Monitor/assets/68577937/51e363b6-731f-47fa-938e-261d922df55a)

![Display 3D](https://github.com/RavinduMPK/Heart-Monitor/assets/68577937/4d077bd3-f08f-4e04-b51a-32fc16e5a873)

