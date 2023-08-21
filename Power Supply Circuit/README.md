## Power Supply Circuit

The power supply circuit in our heart rate monitor project was a critical component that provided the necessary electrical energy for the device to function reliably. Here are the key aspects of our power supply design:

To power our device, we utilized a domestic AC power supply rated at 230V/50Hz. Given the different voltage and nature of the AC supply compared to our device's requirements, we needed to go through several steps of transformation and regulation.

We began by stepping down the voltage from 230V AC to a safer and usable level. To achieve this, we incorporated a 230V to 15V step-down transformer. This initial transformation ensured that the voltage was within an appropriate range for further processing.

The next step was to obtain a stable DC output for the heart rate monitor's internal circuitry. For this purpose, we designed a power supply PCB that included a rectifier bridge and voltage regulators. The rectifier bridge efficiently converted the AC voltage to a pulsating DC voltage, and then we employed L7812 and L7912 voltage regulators to generate +12V and -12V DC outputs, respectively.

As our circuit incorporated operational amplifiers (opamps), it was necessary to have both positive and negative supply voltages. Therefore, the power supply design incorporated both +12V and -12V lines to accommodate the requirements of the opamps.

To ensure smooth and stable DC outputs, we integrated smoothing circuits that reduced the residual ripple in the rectified DC signal. This smoothed DC output was vital to provide a clean and reliable power source for the heart rate monitor's sensitive analog circuitry.

![Power Supply Circuit](https://github.com/RavinduMPK/Heart-Monitor/assets/68577937/2450663c-7d0d-4a42-a042-4cf77d2d5f0d)

![Power Supply PCB](https://github.com/RavinduMPK/Heart-Monitor/assets/68577937/cd4e734a-fa81-4de1-b229-d5bd39dd485c)


![Power Supply PCB 3D](https://github.com/RavinduMPK/Heart-Monitor/assets/68577937/33142b2b-3dd3-4c64-9abd-177890f86390)
