##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab4
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/Users/stevendea/Documents/DataStructuresClass
ProjectPath            :=/Users/stevendea/Documents/DataStructuresClass/Lab4
IntermediateDirectory  :=../build-$(ConfigurationName)/Lab4
OutDir                 :=../build-$(ConfigurationName)/Lab4
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Steven Dea
Date                   :=08/11/2019
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
Objects0=../build-$(ConfigurationName)/Lab4/main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Lab4/Calculator.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Lab4/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/Lab4"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/Lab4"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/Lab4/.d:
	@mkdir -p "../build-$(ConfigurationName)/Lab4"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Lab4/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/Lab4/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/stevendea/Documents/DataStructuresClass/Lab4/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Lab4/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Lab4/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Lab4/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/Lab4/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Lab4/main.cpp$(PreprocessSuffix) main.cpp

../build-$(ConfigurationName)/Lab4/Calculator.cpp$(ObjectSuffix): Calculator.cpp ../build-$(ConfigurationName)/Lab4/Calculator.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/stevendea/Documents/DataStructuresClass/Lab4/Calculator.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Calculator.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Lab4/Calculator.cpp$(DependSuffix): Calculator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Lab4/Calculator.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Lab4/Calculator.cpp$(DependSuffix) -MM Calculator.cpp

../build-$(ConfigurationName)/Lab4/Calculator.cpp$(PreprocessSuffix): Calculator.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Lab4/Calculator.cpp$(PreprocessSuffix) Calculator.cpp


-include ../build-$(ConfigurationName)/Lab4//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


