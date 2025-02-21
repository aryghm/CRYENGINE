// Copyright 2001-2019 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include <CrySchematyc2/Script/IScriptFile.h>

#include "Script/ScriptElementBase.h"
#include "Script/ScriptUserDocumentation.h"
#include "Script/ScriptVariableDeclaration.h"

namespace Schematyc2
{
	class CScriptAbstractInterfaceFunction : public CScriptElementBase<IScriptAbstractInterfaceFunction>
	{
	private:

		typedef std::vector<CScriptVariableDeclaration> Inputs;
		typedef std::vector<CScriptVariableDeclaration> Outputs;

	public:

		// #SchematycTODO : Create two separate constructors: one default (before loading) and one for when element is created in editor.
		CScriptAbstractInterfaceFunction(IScriptFile& file, const SGUID& guid = SGUID(), const SGUID& scopeGUID = SGUID(), const char* szName = nullptr);

		// IScriptElement
		virtual EAccessor GetAccessor() const override;
		virtual SGUID GetGUID() const override;
		virtual SGUID GetScopeGUID() const override;
		virtual bool SetName(const char* szName) override;
		virtual const char* GetName() const override;
		virtual void EnumerateDependencies(const ScriptDependancyEnumerator& enumerator) const override;
		virtual void Refresh(const SScriptRefreshParams& params) override;
		virtual void Serialize(Serialization::IArchive& archive) override;
		virtual void RemapGUIDs(IGUIDRemapper& guidRemapper) override;
		// ~IScriptElement

		// IScriptAbstractInterfaceFunction
		virtual const char* GetAuthor() const override;
		virtual const char* GetDescription() const override;
		virtual size_t GetInputCount() const override;
		virtual const char* GetInputName(size_t inputIdx) const override;
		virtual IAnyConstPtr GetInputValue(size_t inputIdx) const override;
		virtual size_t GetOutputCount() const override;
		virtual const char* GetOutputName(size_t outputIdx) const override;
		virtual IAnyConstPtr GetOutputValue(size_t outputIdx) const override;
		// ~IScriptAbstractInterfaceFunction

	private:

		SGUID                    m_guid;
		SGUID                    m_scopeGUID;
		string                   m_name;
		Inputs                   m_inputs;
		Outputs                  m_outputs;
		SScriptUserDocumentation m_userDocumentation;
	};

	DECLARE_SHARED_POINTERS(CScriptAbstractInterfaceFunction)
}
