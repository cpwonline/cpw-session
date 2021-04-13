# Targets

## Objects libraries

### access_control
add_library(access_control OBJECT "access_control.cc")
target_include_directories(access_control PUBLIC ${HEADER})
set_target_properties(access_control PROPERTIES POSITION_INDEPENDENT_CODE 1)

### dac_list
add_library(dac_list OBJECT "dac_list.cc")
target_include_directories(dac_list PUBLIC ${HEADER})
set_target_properties(dac_list PROPERTIES POSITION_INDEPENDENT_CODE 1)

### expiration
add_library(expiration OBJECT "expiration.cc")
target_include_directories(expiration PUBLIC ${HEADER})
set_target_properties(expiration PROPERTIES POSITION_INDEPENDENT_CODE 1)

### level
add_library(level OBJECT "level.cc")
target_include_directories(level PUBLIC ${HEADER})
set_target_properties(level PROPERTIES POSITION_INDEPENDENT_CODE 1)

### permission
add_library(permission OBJECT "permission.cc")
target_include_directories(permission PUBLIC ${HEADER})
set_target_properties(permission PROPERTIES POSITION_INDEPENDENT_CODE 1)

### session
add_library(session OBJECT "session.cc")
target_include_directories(session PUBLIC ${HEADER})
set_target_properties(session PROPERTIES POSITION_INDEPENDENT_CODE 1)

### user
add_library(user OBJECT "user.cc")
target_include_directories(user PUBLIC ${HEADER})
set_target_properties(user PROPERTIES POSITION_INDEPENDENT_CODE 1)

## Shared and statics libraries

### cpw_session
add_library(${PROJECT_NAME} SHARED "cpw_session.cc")
target_include_directories(${PROJECT_NAME} PUBLIC ${HEADER} ${DEPENDENCY1_INCLUDE_DIRS} ${PROJECT_BINARY_DIR})
target_link_libraries(
	${PROJECT_NAME} PUBLIC
	access_control
	expiration
	level
	permission
	session
	user
	dac_list
)