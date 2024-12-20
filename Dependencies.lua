-- Crono dependencies

IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/CronoEngine/vendor/glfw/include"
IncludeDir["Glad"] = "%{wks.location}/Hazel/vendor/Glad/include"

LibraryDir = {}

Library = {}

-- Windows
Library["WinSock"] = "Ws2_32.lib"
Library["WinMM"] = "Winmm.lib"
Library["WinVersion"] = "Version.lib"
Library["BCrypt"] = "Bcrypt.lib"