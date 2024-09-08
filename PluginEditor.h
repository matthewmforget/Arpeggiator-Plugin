/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class A1StarterAudioProcessorEditor  : public juce::AudioProcessorEditor, private juce::Slider::Listener, public juce::TextEditor::Listener
{
public:
    A1StarterAudioProcessorEditor (A1StarterAudioProcessor&);
    ~A1StarterAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    void updateToggleState(juce::Button* button, juce::String name)
        {
        
            
            auto state = button->getToggleState();

            juce::String stateString = state ? "ON" : "OFF";
            juce::String selectedString = state ? " (selected)" : "";

            juce::Logger::outputDebugString(name + " Button changed to " + stateString);
            button->setButtonText(name + selectedString);
            audioProcessor.desc = false;
            audioProcessor.sandwich = false;
            //audioProcessor.majorTriad = false;
            audioProcessor.asc = ascendButt.getToggleState();
            descendButt.setButtonText("Descending");
        }
    
    void updateToggleStateDescend(juce::Button* button, juce::String name)
        {
        
            
            auto state = button->getToggleState();

            juce::String stateString = state ? "ON" : "OFF";
            juce::String selectedString = state ? " (selected)" : "";

            juce::Logger::outputDebugString(name + " Button changed to " + stateString);
            button->setButtonText(name + selectedString);
            descendButt.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::red);
            audioProcessor.asc = false;
            audioProcessor.sandwich = false;
            //audioProcessor.majorTriad = false;
            audioProcessor.desc = descendButt.getToggleState();
        }
    
    void updateToggleStateSandwich(juce::Button* button, juce::String name)
        {
        
            
            auto state = button->getToggleState();

            juce::String stateString = state ? "ON" : "OFF";
            juce::String selectedString = state ? " (selected)" : "";

            juce::Logger::outputDebugString(name + " Button changed to " + stateString);
            button->setButtonText(name + selectedString);
            audioProcessor.asc = false;
            audioProcessor.desc = false;
            audioProcessor.majorTriad = false;
            audioProcessor.diffDuration = 0;
            audioProcessor.sandwich = sandButt.getToggleState();
        }
    
    void updateToggleStateMajorTriad(juce::Button* button, juce::String name)
        {
        
            
            auto state = button->getToggleState();

            juce::String stateString = state ? "ON" : "OFF";
            juce::String selectedString = state ? " (selected)" : "";

            juce::Logger::outputDebugString(name + " Button changed to " + stateString);
            button->setButtonText(name + selectedString);
            //audioProcessor.asc = false;
            //audioProcessor.desc = false;
            audioProcessor.sandwich = false;
            audioProcessor.diffDuration = 0;
            audioProcessor.majorTriad = majorT.getToggleState();
        }
    
    void updateToggleStateDuration(juce::Button* button, juce::String name)
        {
        
            
            auto state = button->getToggleState();

            juce::String stateString = state ? "ON" : "OFF";
            juce::String selectedString = state ? " (selected)" : "";

            juce::Logger::outputDebugString(name + " Button changed to " + stateString);
            button->setButtonText(name + selectedString);
            //audioProcessor.asc = false;
            //audioProcessor.desc = false;
            //audioProcessor.sandwich = false;
        if (audioProcessor.diffDuration == 0 && !audioProcessor.majorTriad && !audioProcessor.sandwich){
            audioProcessor.diffDuration = 1;
        }
        else {
            audioProcessor.diffDuration = 0;
        }
        juce::Logger::outputDebugString(std::to_string(audioProcessor.diffDuration));
            
        }


private:
    void sliderValueChanged (juce::Slider* slider) override;
    void textEditorTextChanged(juce::TextEditor& editor) override;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    A1StarterAudioProcessor& audioProcessor;

    juce::Slider arpSlider; // [1]
    
    juce::TextButton ascendButt;
    juce::TextButton descendButt;
    juce::TextEditor octaveInput;
    juce::TextButton sandButt;
    juce::TextButton majorT;
    juce::TextButton duration;
    
    juce::Label notice;
    juce::Label oct;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (A1StarterAudioProcessorEditor)
};

