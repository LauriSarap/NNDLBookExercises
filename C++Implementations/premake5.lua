workspace "NNDLC++"
    architecture "x64"
    startproject "Perceptron"

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"

project "Perceptron"
    location "Exercises/%{prj.name}"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "Exercises/%{prj.name}/**.h",
        "Exercises/%{prj.name}/**.cpp"
    }

    includedirs
    {
        "libs/eigen/Eigen"
    }

    filter "configurations:Debug"
		defines "NNDL_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "NNDL_RELEASE"
		runtime "Release"
		optimize "On"