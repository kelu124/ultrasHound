#  usxtracking
Playing with (real?) audio beacon and xtracking devices 

# Principle

SilverPush drops a cookie along with playing an inaudible audio, using speakers as audio beacons. The inaudible code is received and recognized on the mobile device by the software development kit that’s on the phone. This creates an immediate and accurate association between the desktop cookie and mobile device. 


# Stakeholders

## COmpangies

* SilverPush
    *  co-founder Alex Modon
    * https://www.silverpush.co/#!/
* cross-device tracking companies 4Info and Tapad use ultrasonic tracking
* Companies like Drawbridge and Tapad have built cross-device matching platforms using data from multiple devices

## Apps

The mobile application Shopkick, for instance, provides rewards to users if they walk into stores that collaborate with the Shopkick company

Mobile applications like Lisnr and Signal360 present location-specific content

##
_The SilverPush implementation records audio from an available microphone at a sampling rate of 44.1 kHz and directly analyses the recorded data in blocks of 4,096 audio samples. Due to the use of a sampling frequency of 44.1 kHz, the implementation is capable of detecting beacons up to 22 kHz—provided that the available loudspeakers and microphones support such a high frequency. _



# Superb study

* https://www.tu-braunschweig.de/Medien-DB/sec/pubs/2016-batmobile.pdf

 -> Study on "_beacon as used by the Lisnr SDK_"
 -> SilverPush, Lisnr and Shopkick are being studied

We spot ultrasonic beacons in various web media content and detect signals in 4 of 35 stores in two European cities that are used for
location tracking. While we do not find inaudible beacons in TV streams from 7 countries, we spot 223 Android applications that are constantly listening for ultrasonic beacons in the background without the user’s knowledge

In particular, they embed these beacons in the ultrasonic frequency range between 18 and 20 kHz of audio content and detect them with regular mobile applications using the device’s microphone.

We conduct an empirical study to show where ultrasonic audio beacons currently appear. To this end, we implement two detection methods which allow us to efficiently scan audio data and mobile applications for indications of ultrasonic side channels

## detection

Goertzel algorithm: To decode the beacons from the raw audio data, the implementation makes use of the so called Goertzel algorithm, a classic signal processing algorithm that is widely used in telecommunication systems, for example, for identifying DTMF tones in software.


# Letter

* https://www.ftc.gov/system/files/attachments/press-releases/ftc-issues-warning-letters-app-developers-using-silverpush-code/160317samplesilverpushltr.pdf

_The Silverpush code embedded in “XXX” appears similar to the code published by Silverpush in the Google Play store as a demonstration of its audio beacon technology.  For example, the code is configured to access the device’s microphone to collect audio information even when the application is not  in use.  Moreover, your application requires permission to access the mobile device’s microphone prior to install, despite no evident functionality in the application that would require such access._

* https://cdt.org/files/2015/10/10.16.15-CDT-Cross-Device-Comments.pdf

# Source of documents

* http://www.steamfeed.com/silverpush-launches-cross-device-ad-targeting-with-unique-audio-beacon-technology/
* https://www.wired.com/2016/11/block-ultrasonic-signals-didnt-know-tracking/
* https://www.blackhat.com/eu-16/briefings.html#talking-behind-your-back-attacks-and-countermeasures-of-ultrasonic-cross-device-tracking


* https://github.com/MAVProxyUser/SilverPushUnmasked
* https://hackaday.io/project/8353-worlds-smallest-bat-detector
