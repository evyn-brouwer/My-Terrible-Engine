workspace "My-Terrible-Engine"
	architecture "x64"
	configurations {
	"Debug",
	"Release" 
	}
	
project "My-Terrible-Engine"
	kind "ConsoleApp"
	language "C++"
	 targetdir "build/%{cfg.buildcfg}"
	 
	objdir ("build-int/%{cfg.buildcfg}")
	 
	 files
	 {
	 "**.h",
	 "**.cpp"
	 }
	 
	 includedirs
	 {
	 $%{prj.name}/src/;
	 $%{prj.name}/external/;
	 $%{prj.name}/external/GLM/include;
	 $%{prj.name}/external/GLEW/include;
	 $%{prj.name}/external/include;
	 $%{prj.name}/external/SFML-2.5.1/include;
	 
	 }
	 
	 filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
		 "_CONSOLE"
		}
	 
	filter "configurations:Debug" 
		defines "_DEBUG"
		symbols "On"
	
	filters "configurations:Release"
		defines "N_DEBUG"
		optimize "on"