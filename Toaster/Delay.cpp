#include "Delay.h"

Delay::Delay()
{
}

Delay::~Delay()
{
}

void Delay::requestAllValues()
{
  midiRequestType();
  midiRequestOnOffCutsTail();
  midiRequestMix();
  midiRequestVolume();
  midiRequestTime();
  midiRequestRatio();
  midiRequestClockLeft();
  midiRequestClockRight();
  midiRequestFeedback();
  midiRequestBandwidth();
  midiRequestCenterFrequency();
  midiRequestModulation();
  midiRequestOnOffKeepsTail();
  midiRequestDucking();
}

// slots
void Delay::applyType(DelayType type)
{
  midiApplyType((unsigned short) type);
}

void Delay::applyOnOffCutsTail(bool onOffCutsTail)
{
  midiApplyOnOffCutsTail(bool2Raw(onOffCutsTail));
}

void Delay::applyMix(double mix)
{
  midiApplyMix(phys2Raw(mix, 100.0, 0.0));
}

void Delay::applyVolume(double volume)
{
  midiApplyVolume(phys2Raw(volume, 10.0, -5.0));
}

void Delay::applyTime(double time)
{
  midiApplyTime(phys2Raw(time, 1280, 0.0));
}

void Delay::applyRatio(DelayRatio ratio)
{
  midiApplyRatio((unsigned short)ratio);
}

void Delay::applyClockLeft(double clockLeft)
{
  midiApplyClockLeft(phys2Raw(clockLeft, 12.0, 0));
}

void Delay::applyClockRight(double clockRight)
{
  midiApplyClockRight(phys2Raw(clockRight, 12.0, 0));
}

void Delay::applyFeedback(double feedback)
{
  midiApplyFeedback(phys2Raw(feedback, 200.0, 0.0));
}

void Delay::applyBandwidth(double bandwidth)
{
  midiApplyBandwidth(phys2Raw(bandwidth, 10.0, 0.0));
}

void Delay::applyCenterFrequency(double centerFrequency)
{
  midiApplyCenterFrequency(phys2Raw(centerFrequency, 10.0, -5));
}

void Delay::applyModulation(double modulation)
{
  midiApplyModulation(phys2Raw(modulation, 10.0, 0.0));
}

void Delay::applyOnOffKeepsTail(bool onOffKeepsTail)
{
  midiApplyOnOffKeepsTail(bool2Raw(onOffKeepsTail));
}

void Delay::applyDucking(double ducking)
{
  midiApplyDucking(phys2Raw(ducking, 10.0, -5.0));
}

// DelayMidi
void Delay::midiTypeReceived(unsigned short rawVal)
{
  emit typeReceived((DelayType) rawVal);
}

void Delay::midiOnOffCutsTailReceived(unsigned short rawVal)
{
  emit onOffCutsTailReceived(raw2Bool(rawVal));
}

void Delay::midiMixReceived(unsigned short rawVal)
{
  emit mixReceived(raw2Phys(rawVal, 100.0, 0.0));
}

void Delay::midiVolumeReceived(unsigned short rawVal)
{
  emit volumeReceived(raw2Phys(rawVal, 10.0, -5.0));
}

void Delay::midiTimeReceived(unsigned short rawVal)
{
  emit timeReceived(raw2Phys(rawVal, 1280.0, 0.0));
}

void Delay::midiRatioReceived(unsigned short rawVal)
{
  emit ratioReceived((DelayRatio)rawVal);
}

void Delay::midiClockLeftReceived(unsigned short rawVal)
{
  emit clockLeftReceived(raw2Phys(rawVal, 12.0, 0.0));
}

void Delay::midiClockRightReceived(unsigned short rawVal)
{
  emit clockRightReceived(raw2Phys(rawVal, 12.0, 0.0));
}

void Delay::midiFeedbackReceived(unsigned short rawVal)
{
  emit feedbackReceived(raw2Phys(rawVal, 200.0, 0.0));
}

void Delay::midiBandwidthReceived(unsigned short rawVal)
{
  emit bandwidthReceived(raw2Phys(rawVal, 10.0, 0.0));
}

void Delay::midiCenterFrequencyReceived(unsigned short rawVal)
{
  emit centerFrequencyReceived(raw2Phys(rawVal, 10.0, -5.0));
}

void Delay::midiModulationReceived(unsigned short rawVal)
{
  emit modulationReceived(raw2Phys(rawVal, 10.0, 0.0));
}

void Delay::midiOnOffKeepsTailReceived(unsigned short rawVal)
{
  emit onOffKeepsTailReceived(raw2Bool(rawVal));
}

void Delay::midiDuckingReceived(unsigned short rawVal)
{
  emit duckingReceived(raw2Phys(rawVal, 10.0, -5.0));
}
