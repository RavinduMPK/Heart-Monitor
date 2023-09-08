## Component Selection

The process of selecting components for our heart rate monitor project was a critical phase in ensuring the performance, accuracy, and reliability of our device. Among the most pivotal selections were the operational amplifiers (opamps), which are at the heart of our analog circuitry.

A meticulous approach was taken to select opamps for the various circuit blocks. For our instrumentation amplifier—a key element in our circuit—it was imperative to choose opamps with a high Common-Mode Rejection Ratio (CMRR) to effectively suppress common-mode noise. Our selection criteria focused on opamps with a CMRR exceeding 120dB, ensuring that unwanted interference would be significantly attenuated.

In the design of active filters—another crucial component of our circuit—we carefully considered the opamp's slew rate. Slew rate is a key parameter that dictates how quickly an opamp can respond to rapid changes in input signals. Given that our filters play a vital role in shaping and processing the ECG waveform, we opted for opamps with sufficient slew rate to accurately handle the signal dynamics.

For the **_instrumentation amplifier_**, we chose the **_LM4562_** opamp, renowned for its high CMRR and low noise characteristics. This opamp met the stringent requirements of our instrumentation amplifier block, enabling us to amplify the ECG signal while effectively canceling common-mode noise.

In designing our filters, we selected the **_TL072_** and **_TL071_** opamps. These opamps offered an optimal balance between slew rate, noise performance, and compatibility with our filter design requirements. Their ability to handle the intricacies of active filter circuitry contributed to the accurate shaping and conditioning of the ECG waveform.

The component selection process extended beyond opamps to encompass various other components, each chosen with precision to fulfill its specific role in the circuit. By carefully evaluating datasheets, considering performance specifications, and aligning selections with our design goals, we curated a set of components that collectively contributed to the overall success of our heart rate monitor project.
