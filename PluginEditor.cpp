/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
A1StarterAudioProcessorEditor::A1StarterAudioProcessorEditor (A1StarterAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 500);
    
    // these define the parameters of our slider object
    arpSlider.setSliderStyle (juce::Slider::LinearBarVertical);
    arpSlider.setRange (0.0, 1.0, 0.05);
    arpSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 90, 0);
    arpSlider.setPopupDisplayEnabled (true, false, this);
    arpSlider.setTextValueSuffix (" Speed");
    arpSlider.setValue(0.5);
    
    // acend and descend buttons
    ascendButt.onClick = [this] { updateToggleState (&ascendButt,   "Ascending");   };
    descendButt.onClick = [this] { updateToggleStateDescend (&descendButt, "Descending"); };
    addAndMakeVisible(ascendButt);
    ascendButt.setButtonText("Ascending");
    addAndMakeVisible(descendButt);
    descendButt.setButtonText("Descending");
    ascendButt.setClickingTogglesState(true);
    descendButt.setClickingTogglesState(true);
    ascendButt.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::red);
    descendButt.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::red);
    descendButt.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::black);
    ascendButt.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::black);
    
    //sandwich button
    sandButt.onClick = [this] { updateToggleStateSandwich (&sandButt,   "Sandwich");   };
    addAndMakeVisible(sandButt);
    sandButt.setButtonText("Sandwich");
    sandButt.setClickingTogglesState(true);
    sandButt.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::red);
    sandButt.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::black);
    
    // major triad button
    majorT.onClick = [this] { updateToggleStateMajorTriad (&majorT,   "Major Triad");   };
    addAndMakeVisible(majorT);
    majorT.setButtonText("Major Triad");
    majorT.setClickingTogglesState(true);
    majorT.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::red);
    majorT.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::black);
    
    //duration button
    duration.onClick = [this] { updateToggleStateDuration (&duration,   "Fun Duration");   };
    addAndMakeVisible(duration);
    duration.setButtonText("Fun Duration");
    duration.setClickingTogglesState(true);
    duration.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::red);
    duration.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::black);
 
    // this function adds the slider to the editor
    addAndMakeVisible (&arpSlider);
    arpSlider.addListener (this);
    
    // Create a TextEditor for numeric input
    addAndMakeVisible(octaveInput);
    octaveInput.setInputRestrictions(2, "0123456789");
    octaveInput.addListener(this);
    
    //Label
    notice.setText("If a button is red (selected) \n please unselect it before slecting \n another button, or else \n it may not work properly, \n unless they are able to work together. Sandwich\n must be on by itself", juce::dontSendNotification);
    notice.setFont(juce::Font(15.0f, juce::Font::bold));
    notice.setJustificationType(juce::Justification::centred);
    notice.setColour(juce::Label::textColourId, juce::Colours::black);
    addAndMakeVisible(notice);
    
    oct.setText("Choose Number Of Octaves", juce::dontSendNotification);
    oct.setFont(juce::Font(12.0f, juce::Font::bold));
    oct.setJustificationType(juce::Justification::centred);
    oct.setColour(juce::Label::textColourId, juce::Colours::black);
    addAndMakeVisible(oct);

     // Set the initial value
     octaveInput.setText("0");
}

A1StarterAudioProcessorEditor::~A1StarterAudioProcessorEditor()
{
}

//==============================================================================
void A1StarterAudioProcessorEditor::paint (juce::Graphics& g)
{
   // fill the whole window white
    g.fillAll (juce::Colours::white);
 
    // set the current drawing colour to black
    g.setColour (juce::Colours::black);
 
    // set the font size and draw text to the screen
    g.setFont (15.0f);
 
    g.drawFittedText ("Arpeggiator", 0, 0, getWidth(), 30, juce::Justification::centred, 1);
    
    
}

void A1StarterAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    // sets the position and size of the slider with arguments (x, y, width, height)
    arpSlider.setBounds (40, 30, 20, getHeight() - 60);
    ascendButt.setBounds(arpSlider.getX()+50, getHeight() - 100, 100, 50);
    descendButt.setBounds(arpSlider.getX()+50, ascendButt.getY() - 50, 100, 50);
    octaveInput.setBounds(arpSlider.getX()+50, 40, 100, 20);
    sandButt.setBounds(arpSlider.getX()+50, descendButt.getY() - 50, 100, 50);
    majorT.setBounds(arpSlider.getX()+50, sandButt.getY() - 50, 100, 50);
    notice.setBounds(arpSlider.getX()+90, majorT.getY() - 140, 400, 100);
    duration.setBounds(arpSlider.getX()+50, majorT.getY() - 50, 100, 50);
    oct.setBounds(octaveInput.getX()+100, octaveInput.getY()-15, 50, 50);
}

void A1StarterAudioProcessorEditor::sliderValueChanged (juce::Slider* slider)
{
    audioProcessor.arpSpeed = arpSlider.getValue();
}

void A1StarterAudioProcessorEditor::textEditorTextChanged(juce::TextEditor& editor)
{
    // Handle the text change event
    // You can access the numeric value using editor.getText().getIntValue()
    int valueInTextBox = editor.getText().getIntValue();
    // Use the numeric value as needed
    juce::Logger::outputDebugString("Numeric Value: " + juce::String(valueInTextBox));
    audioProcessor.octave = valueInTextBox;
}

