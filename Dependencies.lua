-- Crono dependencies

IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/CronoEngine/vendor/glfw/include"
IncludeDir["Glad"] = "%{wks.location}/CronoEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/CronoEngine/vendor/ImGui"

LibraryDir = {}

Library = {}

-- Windows
Library["WinSock"] = "Ws2_32.lib"
Library["WinMM"] = "Winmm.lib"
Library["WinVersion"] = "Version.lib"
Library["BCrypt"] = "Bcrypt.lib"