# Install files

## Header files
install(
	FILES ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.h 
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(
	FILES 
		${HEADER}/access_control.h
		${HEADER}/cpw_session.h
		${HEADER}/dac_list.h
		${HEADER}/expiration.h
		${HEADER}/level.h
		${HEADER}/permission.h
		${HEADER}/session.h
		${HEADER}/user.h
	DESTINATION 
		${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
)

## Libraries
install(
	TARGETS 
		${PROJECT_NAME}
	DESTINATION 
		${CMAKE_INSTALL_LIBDIR}
)

## Docs files
install(
	FILES 
		${PROJECT_SOURCE_DIR}/README.md
		${PROJECT_SOURCE_DIR}/CODE_OF_CONDUCT.md
		${PROJECT_SOURCE_DIR}/LICENSE
		${PROJECT_SOURCE_DIR}/PULL_REQUEST_TEMPLATE.md
	DESTINATION
		${CMAKE_INSTALL_DOCDIR}
)

## Share files
install(
	FILES ${PROJECT_BINARY_DIR}/share/${PROJECT_NAME}.pc
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)