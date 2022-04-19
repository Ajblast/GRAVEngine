cmake_minimum_required(VERSION 3.21)

maketest(${TargetName}Tests ${DynamicRuntime} ${TargetName})

target_compile_definitions(${TargetName}Tests PUBLIC -D${TestName}_PATH="${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(${TestName} 
	PRIVATE
		"ApplicationTests.cpp"
)
