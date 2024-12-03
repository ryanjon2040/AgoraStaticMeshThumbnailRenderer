@echo off

set engine=UE_unset
set engine_path=unset
if not exist "%engine_path%" goto :error

set plugin_name=AgoraStaticMeshThumbnailRenderer

set base_path=%USERPROFILE%\Desktop\_z\z
set marketplace_package="%base_path%\Compile"
set marketplace_distribute="%base_path%\Dist"

rmdir /s /q %base_path%

echo:
echo Base Path: %base_path%
echo Compile Path: %marketplace_package%
echo ****************************** STEP I - Building for %engine% ******************************

set YETI_STRICT_BUILD=false
call %engine_path%/Engine/Build/BatchFiles/RunUAT.bat BuildPlugin -Plugin=%~dp0%plugin_name%.uplugin -Package=%marketplace_package% -CreateSubFolder -nocompile -nocompileuat

echo:
echo ****************************** STEP II - Preparing Marketplace Build ******************************
robocopy %marketplace_package% %marketplace_distribute% /s /xd Binaries Intermediate
rmdir /s /q %marketplace_package%
%SystemRoot%\explorer.exe %marketplace_distribute%

echo:
echo ****************************** ALL DONE ******************************
set YETI_STRICT_BUILD=true
pause
goto :end

:error
msg * "%engine% does not exist in '%engine_path%'"
:end
