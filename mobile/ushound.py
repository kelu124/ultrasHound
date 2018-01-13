from scipy.io.wavfile import read as wavread
import matplotlib.pyplot as plt
import numpy as np

def USGet(wavfilename,F1,F2):
    
    audiofilename = wavfilename
    [samplerate, x] = wavread(audiofilename) # x is a numpy array of integer, representing the samples 
    # scale to -1.0 -- 1.0
    if x.dtype == 'int16':
        nb_bits = 16 # -> 16-bit wav files
    elif x.dtype == 'int32':
        nb_bits = 32 # -> 32-bit wav files
    max_nb_bit = float(2 ** (nb_bits - 1))
    samples = x / (max_nb_bit + 1.0) # samples is a numpy array of float representing the samples 

    F1 = int(F1)
    F2 = int(F2)
    d1 = int(F1*len(x)/samplerate)
    d2 = int(F2*len(x)/samplerate)

    f = range(len(x))
    for k in range(len(x)):
        f[k] = 1.0e-3*f[k]*samplerate/len(x)
        
    A = np.fft.fft(samples)
    plt.plot(f[d1:d2],np.abs(A)[d1:d2])  
    plt.savefig(wavfilename+'-1.png')
    plt.xlabel("Frequency in kHz")
    plt.title("Overall spectrum of the file: "+wavfilename+".")
    plt.show() 
    
    L = len(x)
    T = 4*1024
    nS = int(L/T)
    dd1 = int(F1*T/samplerate)
    dd2 = int(F2*T/samplerate)

    SP = []
    RawSP = []
    for i in range(nS):
        B = np.fft.fft(samples[i*T:(i+1)*T-1])
        
        B = B / (np.average(np.abs(B[dd1:dd1+60])) + np.average(np.abs(B[dd1+100:dd1+160])) )
        SP.append(np.abs(B[dd1:dd2]))  
        RawSP.append( np.concatenate((B[dd1:dd2], B[T-dd2:T-dd1]), axis=0))
    SPP = np.asarray(SP)

    plt.figure(figsize=(15,5))
    plt.imshow(np.transpose(SPP), cmap='hot',vmin=SPP.min(),vmax=SPP.max()) 
    plt.title("Plot of the "+str(F1/1000)+"kHz to "+str(F2/1000)+"kHz ("+audiofilename+")")
    plt.savefig(wavfilename+'-2.png')
    plt.show()

    return "Done"


if __name__ == "__main__":
    import sys
    USGet(sys.argv[1],sys.argv[2],sys.argv[3])
