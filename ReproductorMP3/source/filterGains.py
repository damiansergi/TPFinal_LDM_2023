import numpy as np
import matplotlib.pyplot as plt
from scipy import signal

# Filter specifications
fs = 44100
fc = [34, 80, 190, 450, 1100, 2500, 6000, 14200]
# Cutoff frequency in normalized frequency (0 to 1)
wc = [2*np.pi*x/fs for x in fc]

G = [0.1] * 8  # Use 3.16227766 to get values in each for the C code
G = [10**(x/20) for x in G]  # If G was created in dB, convert it into times
Q = 1.40845  # 1.23
B = [x/Q for x in wc]
Gb = [x/2 for x in G]
b = [np.sqrt(np.abs(Gb[i]**2-1)/np.abs(G[i]**2-Gb[i]**2))
     * np.tan(B[i]/2) for i in range(len(B))]

n = 65536
result = [0]*n

plt.figure()

for i in range(len(fc)):

    # Design the filter
    numerator = [1+G[i]*b[i], -2*np.cos(wc[i]), (1-G[i]*b[i])]
    denominator = [1+b[i], -2*np.cos(wc[i]), (1-b[i])]

    # Create the transfer function
    filter_system = signal.TransferFunction(numerator, denominator, dt=1/fs)

    # Generate frequency response
    frequency, response = signal.freqz(numerator, denominator, worN=65536)

    # Evaluate the filter response at a specific frequency
    evaluate = [x * 2*np.pi/fs for x in fc]  # Radians per sample
    resp = signal.dfreqresp(filter_system, w=[evaluate])

    # Print the magnitude and phase at the target frequency
    magnitude_at_target = np.abs(resp[1][0])
    formatted_list = [f'{num:.6f}f' for num in 20 *
                      np.log10(np.abs(magnitude_at_target)) / (20*np.log10(np.abs(G)))]

    print("[", end='')
    for formatted_num in formatted_list:
        print(formatted_num, end='')
        print(', ', end='')
    print("]")

    # Plot the frequency response
    plt.semilogx(frequency*fs/(np.pi*2), 20 * np.log10(np.abs(response)))
    result += 20 * np.log10(np.abs(response))

plt.semilogx(frequency*fs/(np.pi*2), result)
plt.title('Filter Frequency Response')
plt.xlabel('Frequency (rad/sample)')
plt.ylabel('Gain (dB)')
plt.grid(True)
plt.show()
