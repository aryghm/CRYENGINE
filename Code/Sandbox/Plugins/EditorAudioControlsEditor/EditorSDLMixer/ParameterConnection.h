// Copyright 2001-2019 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include "../Common/IConnection.h"

#include <PoolObject.h>
#include <CryAudioImplSDLMixer/GlobalData.h>

namespace ACE
{
namespace Impl
{
namespace SDLMixer
{
class CParameterConnection final : public IConnection, public CryAudio::CPoolObject<CParameterConnection, stl::PSyncNone>
{
public:

	CParameterConnection() = delete;
	CParameterConnection(CParameterConnection const&) = delete;
	CParameterConnection(CParameterConnection&&) = delete;
	CParameterConnection& operator=(CParameterConnection const&) = delete;
	CParameterConnection& operator=(CParameterConnection&&) = delete;

	explicit CParameterConnection(
		ControlId const id,
		bool const isAdvanced,
		float const mult,
		float const shift)
		: m_id(id)
		, m_isAdvanced(isAdvanced)
		, m_mult(mult)
		, m_shift(shift)
	{}

	explicit CParameterConnection(ControlId const id)
		: m_id(id)
		, m_isAdvanced(false)
		, m_mult(CryAudio::Impl::SDL_mixer::g_defaultParamMultiplier)
		, m_shift(CryAudio::Impl::SDL_mixer::g_defaultParamShift)
	{}

	virtual ~CParameterConnection() override = default;

	// CBaseConnection
	virtual ControlId GetID() const override final         { return m_id; }
	virtual bool      HasProperties() const override final { return true; }
	virtual void      Serialize(Serialization::IArchive& ar) override;
	// ~CBaseConnection

	bool  IsAdvanced() const;

	float GetMultiplier() const { return m_mult; }
	float GetShift() const      { return m_shift; }

private:

	void Reset();

	ControlId const m_id;
	bool            m_isAdvanced;
	float           m_mult;
	float           m_shift;
};
} // namespace SDLMixer
} // namespace Impl
} // namespace ACE
