# What is ultrasHound ?

Ultrasound, sound with a pitch too high to be heard by us humans, may be used in places to track your behavior, to know where you've been, what channel you're watching on TV, tracking a record of what you watch on YouTube.. without the tracker leaving your pocket.

This project is a first of its kind to serve as a tracker of trackers, to know who tracks you, with what message, mapping the ultrasound-unsafe areas around you, and telling you when you're being spied on.

It could also possibly act as a spoofer. 

### How would it be made ?

Let's KISS

* Arduino
* Electret
* Mini screen
* + signals

### Principles

The signals used to track are in the 18-20kHZ range. Some microphones, like electrets, still receive this range of frequency.

This frequency is to be isolated in the Fourrier space, in a arduino piece of code, cleaned, and analysed.

Any suspicious signals will be tracked.

With enough recordings, we'll work on understanding the communicaton protocol, to use in a last phase.



# Read more

* [Startup uses ultrasound chirps to covertly link and track all your devices](https://boingboing.net/2015/11/13/startup-uses-ultrasound-chirps.html)
* [Ultrasound Tracking Beacons Making Things Sort of Creepy For Consumers](https://www.alienvault.com/blogs/security-essentials/ultrasound-tracking-beacons-making-things-sort-of-creepy-for-consumers)
* [How to Block the Ultrasonic Signals You Didn’t Know Were Tracking You](https://www.wired.com/2016/11/block-ultrasonic-signals-didnt-know-tracking/)
* [Beware of ads that use inaudible sound to link your phone, TV, tablet, and PC](http://arstechnica.com/tech-policy/2015/11/beware-of-ads-that-use-inaudible-sound-to-link-your-phone-tv-tablet-and-pc/) Privacy advocates warn feds about surreptitious cross-device tracking.
