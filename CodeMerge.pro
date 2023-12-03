QMAKE_CXX                       = @echo [C+] $@ && g++ 

QMAKE_CC                        = @echo [C+] $@ && gcc 

QMAKE_MOC                       = @echo [MO] $@ && moc 

QMAKE_LINK                      = @echo [LD] $@ && g++ 

QMAKE_RC                        = @echo [RC] $@ && windres 

#QMAKE_LFLAGS_WINDOWS            += -mwindows -Ld:/usr/local/lib
QMAKE_LFLAGS_WINDOWS            += -Wl,--subsystem,console -Ld:/usr/local/lib

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
				   BuildSource.cpp                              \
				   BuildTarget.cpp                              \
				   CodeDatabase.cpp                             \
				   MainControlBar.cpp                           \
				   MainDisplaySplitter.cpp                      \
				   MainDisplayWindow.cpp                        \
				   MainMessageWindow.cpp                        \
				   MainSettings.cpp                             \
				   MainWindow.cpp                               \
				   MainWindowHeader.cpp                         \
				   ModuleContainerWindow.cpp                    \
				   ModuleSectionWindow.cpp                      \
				   ModuleToolBar.cpp                            \
				   ModuleTree.cpp                               \
				   ModuleTreeModuleSet.cpp                      \
				   ModuleTreeWindow.cpp                         \
				   ModuleWindow.cpp                             \
				   SourceTree.cpp                               \
				   SourceTreeWindow.cpp                         \
				   StringTuple.cpp                              \
				   SystemConfig.cpp                             \
				   TargetTree.cpp                               \
				   TargetTreeWindow.cpp                         \
				   TrackViewContainer.cpp                       \
				   TrackViewWindow.cpp                          \
				   main.cpp                                     \

HEADERS                         += \
				   BuildModule.h                                \
				   BuildModuleSet.h                             \
				   BuildSource.h                                \
				   BuildTarget.h                                \
				   CodeDatabase.h                               \
				   MainControlBar.h                             \
				   MainDisplaySplitter.h                        \
				   MainDisplayWindow.h                          \
				   MainMessageWindow.h                          \
				   MainSettings.h                               \
				   MainWindow.h                                 \
				   MainWindowHeader.h                           \
				   ModuleContainerWindow.h                      \
				   ModuleSectionWindow.h                        \
				   ModuleToolBar.h                              \
				   ModuleTree.h                                 \
				   ModuleTreeModuleSet.h                        \
				   ModuleTreeWindow.h                           \
				   ModuleWindow.h                               \
				   SourceTree.h                                 \
				   SourceTreeWindow.h                           \
				   StringTuple.h                                \
				   SystemConfig.h                               \
				   TargetTree.h                                 \
				   TargetTreeWindow.h                           \
				   TrackViewContainer.h                         \
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
