#include <iostream>
#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 540, "Terraria");

#pragma region imgui
    rlImGuiSetup(true);

    ImGuiIO &io = ImGui::GetIO();
    // io.ConfigFlags |=
    //     ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    // io.ConfigFlags |=
    //     ImGuiConfigFlags_NavEnableGamepad;            // Enable gamepad
    //     Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; // Enable Docking
    io.FontGlobalScale = 1;

    // Themes
    // ImGui::StyleColorsDark();
    // ImGui::StyleColorsLight();
    ImGui::StyleColorsClassic();
#pragma endregion

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

#pragma region imgui
        rlImGuiBegin();

        ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
        ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
        ImGui::PopStyleColor(2);
#pragma endregion

        DrawText("Hello, World!", 190, 200, 20, BLACK);

#pragma region imgui windows
        ImGui::Begin("test");
        ImGui::Text("Speed");
        ImGui::SameLine();
        ImGui::TextDisabled("(?)");

        if (ImGui::IsItemHovered())
        {
            ImGui::BeginTooltip();
            ImGui::Text("Controls how fast the player moves.");
            ImGui::EndTooltip();
        }

        ImGui::End();

        ImGui::Begin("Second window");

        static char buffer[128] = "";

        ImGuiInputTextFlags flags =
            ImGuiInputTextFlags_CharsNoBlank |     // no spaces
            ImGuiInputTextFlags_EnterReturnsTrue | // return true on Enter
            ImGuiInputTextFlags_AutoSelectAll; // select all text when focused

        if (ImGui::InputText("Player Name", buffer, sizeof(buffer), flags))
        {
            std::cout << "Confirmed name: " << buffer << "\n";
        }

        ImGui::End();
#pragma endregion

#pragma region imgui
        rlImGuiEnd();
#pragma endregion

        EndDrawing();
    }

#pragma region imgui
    rlImGuiShutdown();
#pragma endregion

    CloseWindow();

    return 0;
};