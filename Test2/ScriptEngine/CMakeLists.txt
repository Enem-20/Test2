project(ScriptEngine)

add_library(${PROJECT_NAME}
			src/ScriptEngine.h
			src/ScriptEngine.cpp
			src/LuaParser.h
			src/LuaParser.cpp
			src/ClassRegistrator.h
			src/ClassRegistrator.cpp
			src/Headers.h
			)
add_subdirectory(external/Lua)
add_subdirectory(Engine/)

target_include_directories(${PROJECT_NAME} PUBLIC external/sol2/include)

target_link_libraries(${PROJECT_NAME} lua_static Engine)