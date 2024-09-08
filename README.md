**Arpeggiator Audio Plugin**

**Overview**
This is an advanced arpeggiator audio plugin developed using the JUCE framework. The plugin takes MIDI input, processes it to generate arpeggiated notes, and outputs the result as MIDI for further use in a DAW. It provides flexible controls, including customizable octave range, arpeggiation speed, and multiple modes for different musical patterns.

**Features**
Octave Range: Input the number of octaves you want the arpeggiated sequence to span.
Arpeggiator Speed: Adjust the speed of the arpeggiated notes using a slider to sync with the project tempo or to set custom speeds.
Arpeggiator Modes: Several modes for different arpeggiation patterns, including:
Ascending: Plays notes in ascending order.
Descending: Plays notes in descending order.
Major Triad: Arpeggiates notes based on the major triad of the played notes.
More Modes: Explore additional musical patterns that provide creative flexibility for your compositions.

**Files Included**
PluginProcessor.cpp
PluginEditor.cpp
PluginProcessor.h
PluginEditor.h
ArpeggiatorPlugin.jucer
These files comprise the source code and configuration necessary to build and run the plugin.

**Installation & Usage**

**Building the Plugin (macOS - AU)**
Prerequisites:

JUCE Framework: Download JUCE from JUCE's official website.
Xcode: Install Xcode from the Mac App Store for compiling the project.
Steps:

Clone the Repository:
bash:

git clone https://github.com/matthewmforget/Arpeggiator-Plugin.git

Open in Projucer:
Open Projucer from your JUCE installation.
Load the .jucer file by clicking Open Existing Project and navigating to ArpeggiatorPlugin.jucer.
Make sure AU (Audio Unit) is enabled under Plugin Formats in the project settings.
Open in Xcode:
In Projucer, click Save Project and Open in IDE. This will generate Xcode project files and open them in Xcode.
Build in Xcode:
In Xcode, select the Audio Unit target from the scheme dropdown.
Hit Cmd + R or click Run to build the plugin.
Once the build is complete, you will find the .component file in the build folder.
Install the Plugin:
Copy the generated .component file to your Audio Unit plugin folder:
bash:

/Library/Audio/Plug-Ins/Components
Use the Plugin:
Open your DAW (e.g., Logic Pro, Ableton Live).
Rescan your plugins if needed, and insert the arpeggiator on a MIDI track. The plugin will process incoming MIDI notes and generate arpeggiated output based on the configured settings.

**Building the Plugin (VST - Windows/Linux/macOS)**
Prerequisites:

JUCE Framework: Download JUCE from JUCE's official website.
CMake (for Linux) or Xcode (for macOS) or Visual Studio (for Windows) for compiling the project.
Steps:

Clone the Repository:
bash:

git clone https://github.com/<your-username>/<your-repo>.git

Open in Projucer:
Open Projucer and load the .jucer file (ArpeggiatorPlugin.jucer).
In Projucer, make sure VST3 is enabled under Plugin Formats in the project settings.
Open in Your IDE:
In Projucer, click Save Project and Open in IDE. This will open the project in Xcode (macOS), Visual Studio (Windows), or generate build files for CMake (Linux).
Build the Plugin:
macOS: Follow the same steps as the AU build, but make sure the VST3 target is selected.
Windows: Use Visual Studio to compile the project.
Linux: Use CMake to build the project:
bash:

mkdir build
cd build
cmake ..
make
Install the Plugin:
Copy the generated .vst3 file to the appropriate VST3 plugin folder:
macOS: /Library/Audio/Plug-Ins/VST3
Windows: C:\Program Files\Common Files\VST3
Linux: Place the plugin in your DAW's VST3 folder, typically located under ~/.vst3.
Use the Plugin:
Open your DAW (e.g., Ableton Live, Reaper, Cubase).
Rescan your plugins if needed, and insert the arpeggiator on a MIDI track. The plugin will process MIDI input and generate arpeggiated output for further sound synthesis.
