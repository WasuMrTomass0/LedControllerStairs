#pragma once
#include <array>

#include "IInput.h"
#include "Distance.h"
#include "Settings.h"

template<unsigned arraySize>
class InputThresholdDistance : public IInput
{
protected:
	const std::array<IDistance *, arraySize> m_distanceSensors;
	const std::array<TYPE::distance, arraySize> m_thresholds;
public:
	InputThresholdDistance(std::array<IDistance*, arraySize> distanceSensors, std::array<TYPE::distance, arraySize> thresholds, unsigned repetitions)
		: m_distanceSensors(distanceSensors)
		, m_thresholds(thresholds)
		, m_repetitions(repetitions)
	{
	}
	
	virtual bool getOutputState(bool) final {
		for (std::size_t i = 0; i < arraySize; ++i)
		{
			if (m_distanceSensors[i]->getDistance() < m_thresholds[i]) return true;
			return false;
		}
	}

	virtual ~InputThresholdDistance() = default;
};
