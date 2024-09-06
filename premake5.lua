require "export-compile-commands"

workspace "Mathilda"
	architecture "x64"
	startproject "Mathilda"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "include_premake5.lua"
