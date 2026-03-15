#include <windows.h>
#include <string>
#include <filesystem>

std::string GetExecutableDirectory()
{
    char path[MAX_PATH] = {0};
    if (GetModuleFileNameA(nullptr, path, MAX_PATH) == 0)
    {
        return "";
    }

    std::filesystem::path exePath(path);
    return exePath.parent_path().string();
}

bool RunHiddenProcess(const std::string& exePath, const std::string& arguments)
{
    STARTUPINFOA si = {0};
    PROCESS_INFORMATION pi = {0};
    si.cb = sizeof(si);
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_HIDE;

    std::string cmdLine = "\"" + exePath + "\" " + arguments;

    if (!CreateProcessA(nullptr, cmdLine.data(), nullptr, nullptr, FALSE, CREATE_NO_WINDOW, nullptr, nullptr, &si, &pi))
    {
        MessageBoxA(nullptr, "Failed to start lmgrd.exe!", "Error", MB_OK | MB_ICONERROR);
        return false;
    }

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return true;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    std::string exeDir = GetExecutableDirectory();
    if (exeDir.empty())
    {
        MessageBoxA(nullptr, "Failed to get executable directory!", "Error", MB_OK | MB_ICONERROR);
        return 1;
    }

    std::string exePath = exeDir + "\\lmgrd.exe";
    std::string licensePath = exeDir + "\\license.dat";
    std::string arguments = "-c \"" + licensePath + "\" -z";

    RunHiddenProcess(exePath, arguments);

    return 0;
}
