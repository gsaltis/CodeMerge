QMAKE_CXX                       = @echo [C+] $@ && g++ 

QMAKE_CC                        = @echo [C+] $@ && gcc 

QMAKE_MOC                       = @echo [MO] $@ && moc 

QMAKE_LINK                      = @echo [LD] $@ && g++ 

QMAKE_RC                        = @echo [RC] $@ && windres 

QMAKE_LFLAGS_WINDOWS            += -mwindows -Ld:/usr/local/lib

QMAKE_CXXFLAGS                  += -Id:/usr/local/include

QMAKE_LIBS                      = -lwsock32 -ltraceclient -lsqlite3

TARGET                          = CodeMerge

VERSION                         = "0.0.0"
QMAKE_TARGET_COMPANY            = "Greg Saltis"

QMAKE_TARGET_PRODUCT            = "CodeMerge"

QMAKE_TARGET_COPYRIGHT          = "Copyright (C) 2023 Greg Saltis"

QT                              += core gui widgets

DEFINES                         += \

SOURCES                         += \
				   BuildModule.cpp                              \
				   BuildModuleSet.cpp                           \
				   CodeDatabase.cpp                             \
				   MainControlBar.cpp                           \
				   MainDisplayWindow.cpp                        \
				   MainMessageWindow.cpp                        \
				   MainSettings.cpp                             \
				   MainWindow.cpp                               \
				   MainWindowHeader.cpp                         \
				   ModuleSectionWindow.cpp                      \
				   ModuleWindow.cpp                             \
				   SystemConfig.cpp                             \
				   TrackViewWindow.cpp                          \
				   main.cpp                                     \

HEADERS                         += \
				   BuildModule.h                                \
				   BuildModuleSet.h                             \
				   CodeDatabase.h                               \
				   MainControlBar.h                             \
				   MainDisplayWindow.h                          \
				   MainMessageWindow.h                          \
				   MainSettings.h                               \
				   MainWindow.h                                 \
				   MainWindowHeader.h                           \
				   ModuleSectionWindow.h                        \
				   ModuleWindow.h                               \
				   SystemConfig.h                               \
				   TrackViewWindow.h                            \

FORMS                           += \

QMAKE_EXTRA_TARGETS             += junkclean
junkclean.target                = junkclean
junkclean.commands              = @echo Removing junk                           \
                                  && rm -rf $(wildcard core* *~)
junkclean.depends               = 

QMAKE_EXTRA_TARGETS             += cleanall
cleanall.target                 = cleanall
cleanall.commands               = 
cleanall.depends                = junkclean                                     \
                                  clean
