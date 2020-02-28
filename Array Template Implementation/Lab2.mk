##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab2
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/Users/stevendea/Documents/DataStructuresClass
ProjectPath            :=/Users/stevendea/Documents/DataStructuresClass/Lab2
IntermediateDirectory  :=../build-$(ConfigurationName)/Lab2
OutDir                 :=../build-$(ConfigurationName)/Lab2
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Steven Dea
Date                   :=24/10/2019
CodeLitePath           :="/Users/stevendea/Library/Application Support/CodeLite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS := -std=c++17 -Wall -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/private/var/folders/t6/6x96cfv92f7c5p3x9y7ts5lc0000gn/T/AppTranslocation/6A3727AA-5CDE-40A8-9E5C-4456DD09754B/d/codelite.app/Contents/SharedSupport/
Objects0=../build-$(ConfigurationName)/Lab2/main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Lab2/Currency.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Lab2/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/Lab2"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/Lab2"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/Lab2/.d:
	@mkdir -p "../build-$(ConfigurationName)/Lab2"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Lab2/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/Lab2/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/stevendea/Documents/DataStructuresClass/Lab2/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Lab2/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Lab2/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Lab2/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/Lab2/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Lab2/main.cpp$(PreprocessSuffix) main.cpp

../build-$(ConfigurationName)/Lab2/Currency.cpp$(ObjectSuffix): Currency.cpp ../build-$(ConfigurationName)/Lab2/Currency.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/stevendea/Documents/DataStructuresClass/Lab2/Currency.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Currency.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Lab2/Currency.cpp$(DependSuffix): Currency.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Lab2/Currency.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Lab2/Currency.cpp$(DependSuffix) -MM Currency.cpp

../build-$(ConfigurationName)/Lab2/Currency.cpp$(PreprocessSuffix): Currency.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Lab2/Currency.cpp$(PreprocessSuffix) Currency.cpp


-include ../build-$(ConfigurationName)/Lab2//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


