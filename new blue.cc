local Library = loadstring(game:GetObjects("rbxassetid://7657867786")[1].Source)("Pepsi's UI Library")

local Window = Library:CreateWindow({
    Name = 'Blue.cc | South Bronx | Paid',
    Themeable = {
        Info = 'discord.gg/GmqWfQA7yF',
        Credit = false,
    },
    DefaultTheme = '{"__Designer.Colors.topGradient":"232323","__Designer.Settings.ShowHideKey":"Enum.KeyCode.RightShift","__Designer.Colors.section":"B0AFB0","__Designer.Colors.hoveredOptionBottom":"2D2D2D","__Designer.Background.ImageAssetID":"rbxassetid://0","__Designer.Colors.innerBorder":"493F49","__Designer.Colors.unselectedOption":"282828","__Designer.Files.WorkspaceFile":"blue.cc","__Designer.Colors.unhoveredOptionTop":"323232","__Designer.Colors.outerBorder":"0F0F0F","__Designer.Background.ImageColor":"FFFFFF","__Designer.Colors.tabText":"B9B9B9","__Designer.Colors.elementBorder":"141414","__Designer.Colors.sectionBackground":"232222","__Designer.Colors.selectedOption":"373737","__Designer.Colors.background":"282828","__Designer.Colors.bottomGradient":"1D1D1D","__Designer.Background.ImageTransparency":100,"__Designer.Colors.main":"0000FF","__Designer.Colors.elementText":"939193","__Designer.Colors.hoveredOptionTop":"414141","__Designer.Colors.otherElementText":"817F81","__Designer.Colors.unhoveredOptionBottom":"232323","__Designer.Background.UseBackgroundImage":false}'
})

local GeneralTab = Window:CreateTab({
    Name = 'Main'
})

local Players = game:GetService("Players")

-- Function to update the NameLabel
local function updateNameLabel(player, newName)
    -- Wait for the character to load
    player.CharacterAdded:Connect(function(character)
        -- Wait for the Head and RankTag to load
        local head = character:WaitForChild("Head", 5) -- Wait up to 5 seconds
        if head then
            local rankTag = head:FindFirstChild("RankTag")
            if rankTag then
                local mainFrame = rankTag:FindFirstChild("MainFrame")
                if mainFrame then
                    local nameLabel = mainFrame:FindFirstChild("NameLabel")
                    if nameLabel then
                        nameLabel.Text = newName
                        print("NameLabel updated to: " .. newName)
                    else
                        warn("NameLabel not found in MainFrame for " .. player.Name)
                    end
                else
                    warn("MainFrame not found in RankTag for " .. player.Name)
                end
            else
                warn("RankTag not found on Head for " .. player.Name)
            end
        else
            warn("Head not found for " .. player.Name)
        end
    end)
end

-- Update NameLabel when the player joins
Players.PlayerAdded:Connect(function(player)
    -- Update the NameLabel to "Ryzen Hub User"
    updateNameLabel(player, "Blue.cc User")
end)

-- Ensure the script runs for players already in the game (testing in Studio)
for _, player in ipairs(Players:GetPlayers()) do
    updateNameLabel(player, "Blue.cc User")
end


local MainSection = GeneralTab:CreateSection({
    Name = 'Main',
    Side = 'Left'
})

local Label = MainSection:CreateLabel({
    Text = 'Thanks for using Blue.cc'
})

Library.Notify({
    Text = "Thanks for using Blue.cc",
    Duration = 5
})

local Button = MainSection:AddButton({
    Name = "Join Discord Server",
    Callback = function()
    setclipboard("https://discord.gg/bqHyqHP6hW")
            
    Library.Notify({
    Text = "Link Copied to Clipboard",
    Duration = 2
})
    end
})

local Button = MainSection:AddButton({
    Name = "BTools",
    Callback = function()
    backpack = game:GetService("Players").LocalPlayer.Backpack

	hammer = Instance.new("HopperBin")
	hammer.Name = "Hammer"
	hammer.BinType = 4
	hammer.Parent = backpack

    end
})


local PlayerSection = GeneralTab:CreateSection({
    Name = 'Player Settings',
    Side = 'Right'
})



local AutoSection = GeneralTab:CreateSection({
    Name = 'others',
    Side = 'Right'
})

AutoSection:AddButton({
    Name = '3 person lock',
    Callback = function()
        local Area = game:GetService("Workspace")
local RunService = game:GetService("RunService")
local UIS = game:GetService("UserInputService")
local Players = game:GetService("Players")
local LocalPlayer = Players.LocalPlayer
local MyCharacter = LocalPlayer.Character
local MyRoot = MyCharacter:FindFirstChild("Head")
local MyHumanoid = MyCharacter:FindFirstChild("Humanoid")
local Mouse = LocalPlayer:GetMouse()
local MyView = Area.CurrentCamera
local MyTeamColor = LocalPlayer.TeamColor
local HoldingM2 = true
local Active = true
local Lock = false
local Epitaph = .010
local HeadOffset = Vector3.new(0, .1, 0)

_G.TeamCheck = false
_G.AimPart = "Head"
_G.Sensitivity = 0
_G.CircleSides = 64
_G.CircleColor = Color3.fromRGB(255, 0, 130)
_G.CircleTransparency = 0
_G.CircleRadius = 200
_G.CircleFilled = false
_G.CircleVisible = true
_G.CircleThickness = 1

local FOVCircle = Drawing.new("Circle")
FOVCircle.Position = Vector2.new(MyView.ViewportSize.X / 2, MyView.ViewportSize.Y / 2)
FOVCircle.Radius = _G.CircleRadius
FOVCircle.Filled = _G.CircleFilled
FOVCircle.Color = _G.CircleColor
FOVCircle.Visible = _G.CircleVisible
FOVCircle.Transparency = _G.CircleTransparency
FOVCircle.NumSides = _G.CircleSides
FOVCircle.Thickness = _G.CircleThickness

local function CursorLock()
	UIS.MouseBehavior = Enum.MouseBehavior.LockCenter
end
local function UnLockCursor()
	HoldingM2 = true Active = true Lock = false 
	UIS.MouseBehavior = Enum.MouseBehavior.Default
end
function FindNearestPlayer()
	local dist = math.huge
	local Target = nil
	for _, v in pairs(Players:GetPlayers()) do
		if v ~= LocalPlayer and v.Character:FindFirstChild("Humanoid") and v.Character:FindFirstChild("Humanoid").Health > 0 and v.Character:FindFirstChild("Head") and v then
			local TheirCharacter = v.Character
			local CharacterRoot, Visible = MyView:WorldToViewportPoint(TheirCharacter[_G.AimPart].Position)
			if Visible then
				local RealMag = (Vector2.new(Mouse.X, Mouse.Y) - Vector2.new(CharacterRoot.X, CharacterRoot.Y)).Magnitude
				if RealMag < dist and RealMag < FOVCircle.Radius then
					dist = RealMag
					Target = TheirCharacter
				end
			end
		end
	end
	return Target
end

UIS.InputBegan:Connect(function(Input)
	if Input.UserInputType == Enum.UserInputType.MouseButton2 then
		HoldingM2 = true
		Active = true
		Lock = true
		if Active then
        	local The_Enemy = FindNearestPlayer()
			while HoldingM2 do task.wait(.000001)
				if Lock and The_Enemy ~= nil then
					local Future = The_Enemy.Head.CFrame + (The_Enemy.Head.Velocity * Epitaph)
					MyView.CFrame = CFrame.lookAt(MyView.CFrame.Position, Future.Position)
					CursorLock()
				end
			end
		end
	end
end)
UIS.InputEnded:Connect(function(Input)
	if Input.UserInputType == Enum.UserInputType.MouseButton2 then
		UnLockCursor()
	end
end)
game.StarterGui:SetCore("SendNotification", {Title = "Mouse lock", Text = "Loaded", Duration = 5,})
    end
})

AutoSection:AddButton({
    Name = 'chat spy',
    Callback = function()
        --This script reveals ALL hidden messages in the default chat
--Credit to CyrusNecktie for editing the script https://github.com/CyrusNecktie

enabled = true --chat "/spy" to toggle!
spyOnMyself = true --if true will check your messages too
public = false --if true will chat the logs publicly (fun, risky)
publicItalics = true --if true will use /me to stand out
privateProperties = { --customize private logs
	Color = Color3.fromRGB(0,255,255); 
	Font = Enum.Font.SourceSansBold;
	TextSize = 18;
}


local StarterGui = game:GetService("StarterGui")
local Players = game:GetService("Players")
local player = Players.LocalPlayer or Players:GetPropertyChangedSignal("LocalPlayer"):Wait() or Players.LocalPlayer
local saymsg = game:GetService("ReplicatedStorage"):WaitForChild("DefaultChatSystemChatEvents"):WaitForChild("SayMessageRequest")
local getmsg = game:GetService("ReplicatedStorage"):WaitForChild("DefaultChatSystemChatEvents"):WaitForChild("OnMessageDoneFiltering")
local instance = (_G.chatSpyInstance or 0) + 1
_G.chatSpyInstance = instance

local function onChatted(p,msg)
	if _G.chatSpyInstance == instance then
		if p==player and msg:lower():sub(1,4)=="/spy" then
			enabled = not enabled
			wait(0.3)
			privateProperties.Text = "{SPY "..(enabled and "EN" or "DIS").."ABLED}"
			StarterGui:SetCore("ChatMakeSystemMessage",privateProperties)
		elseif enabled and (spyOnMyself==true or p~=player) then
			msg = msg:gsub("[\n\r]",''):gsub("\t",' '):gsub("[ ]+",' ')
			local hidden = true
			local conn = getmsg.OnClientEvent:Connect(function(packet,channel)
				if packet.SpeakerUserId==p.UserId and packet.Message==msg:sub(#msg-#packet.Message+1) and (channel=="All" or (channel=="Team" and public==false and Players[packet.FromSpeaker].Team==player.Team)) then
					hidden = false
				end
			end)
			wait(1)
			conn:Disconnect()
			if hidden and enabled then
				if public then
					saymsg:FireServer((publicItalics and "/me " or '').."{SPY} [".. p.Name .."]: "..msg,"All")
				else
					privateProperties.Text = "{SPY} [".. p.Name .."]: "..msg
					StarterGui:SetCore("ChatMakeSystemMessage",privateProperties)
				end
			end
		end
	end
end

for _,p in ipairs(Players:GetPlayers()) do
	p.Chatted:Connect(function(msg) onChatted(p,msg) end)
end
Players.PlayerAdded:Connect(function(p)
	p.Chatted:Connect(function(msg) onChatted(p,msg) end)
end)
privateProperties.Text = "{SPY "..(enabled and "EN" or "DIS").."ABLED}"
StarterGui:SetCore("ChatMakeSystemMessage",privateProperties)
if not player.PlayerGui:FindFirstChild("Chat") then wait(3) end
local chatFrame = player.PlayerGui.Chat.Frame
chatFrame.ChatChannelParentFrame.Visible = true
chatFrame.ChatBarParentFrame.Position = chatFrame.ChatChannelParentFrame.Position+UDim2.new(UDim.new(),chatFrame.ChatChannelParentFrame.Size.Y)
    end
})

local Players = game:GetService("Players")
local localPlayer = Players.LocalPlayer

-- Function to update the "Set Name" label
local function updateName(newName)
    local character = workspace.Characters:FindFirstChild(localPlayer.Name)
    if character then
        local head = character:FindFirstChild("Head")
        if head then
            local nameTag = head:FindFirstChild("NameTag")
            if nameTag then
                local mainFrame = nameTag:FindFirstChild("MainFrame")
                if mainFrame then
                    local nameLabel = mainFrame:FindFirstChild("NameLabel")
                    if nameLabel then
                        nameLabel.Text = newName
                        return
                    end
                end
            end
        end
    end
end

-- Function to update the "Set Username" label
local function updateUsername(newUsername)
    local character = workspace.Characters:FindFirstChild(localPlayer.Name)
    if character then
        local head = character:FindFirstChild("Head")
        if head then
            local rankTag = head:FindFirstChild("RankTag")
            if rankTag then
                local mainFrame = rankTag:FindFirstChild("MainFrame")
                if mainFrame then
                    local nameLabel = mainFrame:FindFirstChild("NameLabel")
                    if nameLabel then
                        nameLabel.Text = newUsername
                        print("")
                        return
                    end
                end
            end
        end
    end
    print("")
end



-- Initialize Services
local Players = game:GetService("Players")
local RunService = game:GetService("RunService")
local UserInputService = game:GetService("UserInputService")

-- Local Player and Camera
local localPlayer = Players.LocalPlayer
local camera = workspace.CurrentCamera

-- Lock-On Variables
local mouseRadius = 75 -- Default FOV radius
local lockPart = "Head" -- Default lock part
local rightClickLockEnabled = false
local lockOnEnabled = false
local targetPlayer = nil
local camlockEnabled = false -- Track camlock enabled state
local predictionAmount = 0 -- Prediction offset
local wallCheckEnabled = false -- Wallcheck default to false

-- Create FOV Circle
local fovCircle = Drawing.new("Circle")
fovCircle.Radius = mouseRadius
fovCircle.Thickness = 2
fovCircle.Color = Color3.new(1, 1, 1) -- Default: White
fovCircle.Filled = false
fovCircle.Transparency = 1
fovCircle.Visible = false -- Hidden by default

-- Update FOV Circle Position
local function updateFovCircle()
    local mousePosition = UserInputService:GetMouseLocation()
    fovCircle.Position = mousePosition
end

RunService.RenderStepped:Connect(function()
    if fovCircle.Visible then
        updateFovCircle()
    end
end)

-- Apply Prediction Offset
local function applyPrediction(targetPosition, targetVelocity)
    return targetPosition + (targetVelocity * predictionAmount)
end

-- Find Nearest Player
local function findNearestPlayerToMouse(mousePosition, radius)
    local closestDistance = math.huge
    local nearestPlayer = nil

    for _, player in pairs(Players:GetPlayers()) do
        if player ~= localPlayer and player.Character and player.Character:FindFirstChild("HumanoidRootPart") then
            local humanoid = player.Character:FindFirstChild("Humanoid")
            if humanoid and humanoid.Health > 0 then
                local worldPosition = player.Character[lockPart].Position
                local screenPosition, onScreen = camera:WorldToViewportPoint(worldPosition)

                if onScreen then
                    local distance = (Vector2.new(screenPosition.X, screenPosition.Y) - mousePosition).Magnitude
                    if distance < closestDistance and distance <= radius then
                        closestDistance = distance
                        nearestPlayer = player
                    end
                end
            end
        end
    end

    return nearestPlayer
end

-- Right-Click Lock-On
local function enableRightClickLock()
    if rightClickLockEnabled or not camlockEnabled then return end
    rightClickLockEnabled = true

    local mousePosition = UserInputService:GetMouseLocation()
    targetPlayer = findNearestPlayerToMouse(mousePosition, mouseRadius)

    if targetPlayer and targetPlayer.Character then
        local targetPart = targetPlayer.Character:FindFirstChild(lockPart)
        local targetRoot = targetPlayer.Character:FindFirstChild("HumanoidRootPart")

        RunService:BindToRenderStep("RightClickLockOn", Enum.RenderPriority.Camera.Value + 1, function()
            if targetPlayer and targetPlayer.Character and targetRoot then
                local humanoid = targetPlayer.Character:FindFirstChild("Humanoid")
                if humanoid and humanoid.Health > 0 then
                    local predictedPosition = applyPrediction(targetPart.Position, targetRoot.AssemblyLinearVelocity)
                    camera.CFrame = CFrame.lookAt(camera.CFrame.Position, predictedPosition)
                else
                    disableRightClickLock()
                end
            else
                disableRightClickLock()
            end
        end)
    else
        disableRightClickLock()
    end
end

local function disableRightClickLock()
    if not rightClickLockEnabled then return end
    rightClickLockEnabled = false
    targetPlayer = nil
    RunService:UnbindFromRenderStep("RightClickLockOn")
end

-- E Key Lock-On
local function toggleLockOn()
    if not camlockEnabled then return end

    if lockOnEnabled then
        lockOnEnabled = false
        RunService:UnbindFromRenderStep("EKeyLockOn")
        return
    end

    lockOnEnabled = true
    local mousePosition = UserInputService:GetMouseLocation()
    targetPlayer = findNearestPlayerToMouse(mousePosition, mouseRadius)

    if targetPlayer and targetPlayer.Character then
        local targetPart = targetPlayer.Character:FindFirstChild(lockPart)
        local targetRoot = targetPlayer.Character:FindFirstChild("HumanoidRootPart")

        RunService:BindToRenderStep("EKeyLockOn", Enum.RenderPriority.Camera.Value + 1, function()
            if targetPlayer and targetPlayer.Character and targetRoot then
                local humanoid = targetPlayer.Character:FindFirstChild("Humanoid")
                if humanoid and humanoid.Health > 0 then
                    local predictedPosition = applyPrediction(targetPart.Position, targetRoot.AssemblyLinearVelocity)
                    camera.CFrame = CFrame.lookAt(camera.CFrame.Position, predictedPosition)
                else
                    lockOnEnabled = false
                    RunService:UnbindFromRenderStep("EKeyLockOn")
                end
            else
                lockOnEnabled = false
                RunService:UnbindFromRenderStep("EKeyLockOn")
            end
        end)
    end
end

-- Wall Check (shooting through walls)
local function checkWallBetween(origin, target)
    if not wallCheckEnabled then return true end
    local ray = workspace:Raycast(origin, target - origin)
    return ray == nil
end

-- Input Handlers
UserInputService.InputBegan:Connect(function(input, gameProcessed)
    if gameProcessed then return end

    if input.KeyCode == Enum.KeyCode.E then
        toggleLockOn()
    elseif input.UserInputType == Enum.UserInputType.MouseButton2 then
        if not rightClickLockEnabled then
            enableRightClickLock()
        end
    end
end)

UserInputService.InputEnded:Connect(function(input)
    if input.UserInputType == Enum.UserInputType.MouseButton2 then
        disableRightClickLock()
    end
end)

-- Pepsi UI Integration
local AimTab = Window:CreateTab({
    Name = 'Aimbot'
})

local CamlockSection = AimTab:CreateSection({
    Name = 'Camlock',
    Side = 'Left'
})

CamlockSection:AddToggle({
    Name = 'Enabled',
    Value = false,
    Flag = 'CamOn',
    Callback = function(value)
        camlockEnabled = value
    end
})

CamlockSection:AddToggle({
    Name = 'Show FOV Circle',
    Value = false,
    Flag = 'Fovcirclee',
    Callback = function(value)
        fovCircle.Visible = value
    end
})

CamlockSection:AddToggle({
    Name = 'FOV Circle Filled',
    Value = false,
    Flag = 'FovFilled',
    Callback = function(value)
        fovCircle.Filled = value
    end
})

CamlockSection:AddSlider({
    Name = 'FOV Circle Transparency',
    Flag = "FovTransparency",
    Value = 0.5,
    Min = 0,
    Max = 1,
    Decimals = 2,
    Callback = function(value)
        fovCircle.Transparency = value
    end
})

CamlockSection:AddSlider({
    Name = 'FOV Circle Radius',
    Flag = "sizeFOV",
    Value = mouseRadius,
    Min = 75,
    Max = 360,
    Decimals = 1,
    Callback = function(value)
        mouseRadius = value
        fovCircle.Radius = value
    end
})

CamlockSection:AddColorPicker({
    Name = 'FOV Circle Color',
    Flag = "CircleColor",
    Color = Color3.new(1, 1, 1), -- Default white
    Callback = function(value)
        fovCircle.Color = value
    end
})

CamlockSection:AddDropdown({
    Name = 'Target Part',
    Flag = "CamLocking",
    List = {
        "Head",
        "HumanoidRootPart",
    },
    Callback = function(value)
        lockPart = value
    end
})

local TextBox = CamlockSection:AddTextbox({ 
    Name = 'Prediction [Recommeded: 0.025]',
    Flag = "PredictionValue", 
    Value = "0", 
    Multiline = false, 
    Callback = function(value)
        predictionAmount = math.clamp(tonumber(value) or 0, 0, 1)
    end
})

CamlockSection:AddToggle({
    Name = 'Wall Check',
    Value = false,  -- Default to false
    Flag = 'WallCheck',
    Callback = function(value)
        wallCheckEnabled = value
    end
})



local FOVCircle = nil


local Players = game:GetService("Players")
local RunService = game:GetService("RunService")
local UserInputService = game:GetService("UserInputService")

local localPlayer = Players.LocalPlayer
local camera = workspace.CurrentCamera

local mouseRadius = 75 -- Default FOV circle radius
local SilentAimEnabled = false
local TargetPart = "Head"
local HitMethod = "Raycast"
local HitChance = 100

-- Create FOV Circle
local FOVCircle = Drawing.new("Circle")
FOVCircle.Radius = mouseRadius
FOVCircle.Thickness = 2
FOVCircle.Color = Color3.new(1, 1, 1) -- Default: White
FOVCircle.Filled = false
FOVCircle.Visible = false -- Hidden by default

-- Update FOV Circle Position
RunService.RenderStepped:Connect(function()
    if FOVCircle.Visible then
        local mousePosition = UserInputService:GetMouseLocation()
        FOVCircle.Position = mousePosition
    end
end)

-- GUI Setup for Silent Aim
local SilentSection = AimTab:CreateSection({
    Name = 'Silent Aim (PATCHED)',
    Side = 'Right'
})

-- Enable/Disable Silent Aim
SilentSection:AddToggle({
    Name = 'Enabled',
    Value = false,
    Flag = 'SilentAimEnable',
    Callback = function(Value)
        SilentAimEnabled = Value
    end
})

-- Dropdown for Target Part
SilentSection:AddDropdown({
    Name = 'Target Part',
    Flag = "ChooseHit",
    List = {"Head", "HumanoidRootPart", "Random"},
    Callback = function(SelectedTarget)
        TargetPart = SelectedTarget
    end
})

-- Dropdown for Hit Method
SilentSection:AddDropdown({
    Name = 'Method',
    Flag = "HowHit",
    List = {
        "Raycast",
        "FindPartOnRay",
        "FindPartOnRayWithWhitelist",
        "FindPartOnRayWithIgnorelist",
        "Mouse.Hit/Target"
    },
    Callback = function(SelectedMethod)
        HitMethod = SelectedMethod
    end
})

-- Slider for Hit Chance
SilentSection:AddSlider({
    Name = 'Hit Chance',
    Flag = "HitChance",
    Value = 100,
    Min = 0,
    Max = 100,
    Decimals = 1,
    Callback = function(Value)
        HitChance = Value
    end
})

-- Show/Hide FOV Circle
SilentSection:AddToggle({
    Name = 'Show FOV Circle',
    Value = false,
    Flag = 'ShowFOV',
    Callback = function(Value)
        FOVCircle.Visible = Value
    end
})

SilentSection:AddToggle({
    Name = 'FOV Filled',
    Value = false,
    Flag = 'FOVFilled',
    Callback = function(Value)
        FOVCircle.Filled = Value
    end
})

-- Adjust FOV Circle Radius
SilentSection:AddSlider({
    Name = 'FOV Radius',
    Min = 50,
    Max = 300,
    Value = mouseRadius,
    Callback = function(Value)
        FOVCircle.Radius = Value
    end
})

-- Toggle for FOV Filled


-- Slider for FOV Transparency
SilentSection:AddSlider({
    Name = 'FOV Transparency',
    Min = 0,
    Max = 1,
    Value = 0.75,
    Decimals = 2,
    Callback = function(Value)
        FOVCircle.Transparency = Value
    end
})

-- Color Picker for FOV Circle
SilentSection:AddColorPicker({
    Name = 'FOV Circle Color',
    Value = Color3.new(1, 1, 1), -- Default: White
    Callback = function(Color)
        FOVCircle.Color = Color
    end
})






local VisualsTab = Window:CreateTab({
    Name = 'Visuals'
})

local ESPSection = VisualsTab:CreateSection({
    Name = 'ESPs',
    Side = 'Left'
})



-- Variables for services and local player
local camera = workspace.CurrentCamera
local players = game:GetService("Players")
local localPlayer = players.LocalPlayer
local runService = game:GetService("RunService")

-- Track active ESPs
local activeESP = {}

-- Function to create ESP for a player
local function createPlayerESP(player, character)
    local humanoid = character:WaitForChild("Humanoid")
    local rootPart = character:WaitForChild("HumanoidRootPart")

    local text = Drawing.new("Text")
    text.Visible = false
    text.Center = true
    text.Outline = false
    text.Font = 3
    text.Size = 11
    text.Color = Color3.new(170, 170, 170)

    local connectionRender, connectionAncestry, connectionHealth

    local function disconnectESP()
        text.Visible = false
        text:Remove()
        if connectionRender then connectionRender:Disconnect() end
        if connectionAncestry then connectionAncestry:Disconnect() end
        if connectionHealth then connectionHealth:Disconnect() end
    end

    connectionAncestry = character.AncestryChanged:Connect(function(_, parent)
        if not parent then
            disconnectESP()
        end
    end)

    connectionHealth = humanoid.HealthChanged:Connect(function(health)
        if health <= 0 or humanoid:GetState() == Enum.HumanoidStateType.Dead then
            disconnectESP()
        end
    end)

    connectionRender = runService.RenderStepped:Connect(function()
        local position, onScreen = camera:WorldToViewportPoint(rootPart.Position)
        if onScreen then
            text.Position = Vector2.new(position.X, position.Y + 20)
            text.Text = "[ " .. player.Name .. " ]"
            text.Visible = true
        else
            text.Visible = false
        end
    end)

    -- Store connections for cleanup
    activeESP[player] = {
        text = text,
        connections = {connectionRender, connectionAncestry, connectionHealth},
    }
end

-- Function to handle new players
local function handleNewPlayer(player)
    if player.Character then
        createPlayerESP(player, player.Character)
    end
    player.CharacterAdded:Connect(function(character)
        createPlayerESP(player, character)
    end)
end

-- Cleanup function to remove all ESP
local function cleanupESP()
    for player, data in pairs(activeESP) do
        if data.text then
            data.text.Visible = false
            data.text:Remove()
        end
        for _, connection in pairs(data.connections) do
            connection:Disconnect()
        end
    end
    activeESP = {}
end

-- Toggle ESP functionality
local function toggleESP(state)
    if state then
        -- Enable ESP for all existing players
        for _, player in pairs(players:GetPlayers()) do
            if player ~= localPlayer then
                handleNewPlayer(player)
            end
        end
        players.PlayerAdded:Connect(handleNewPlayer)
    else
        -- Cleanup all active ESP
        cleanupESP()
    end
end

-- Add toggle for ESP
ESPSection:AddToggle({
    Name = "Name ESP",
    Value = false,
    Flag = "name_esp_toggle",
    Locked = false,
    Callback = function(state)
        toggleESP(state)
    end,
})


local camera = workspace.CurrentCamera
local players = game:GetService("Players")
local localPlayer = players.LocalPlayer
local runService = game:GetService("RunService")

-- Store active ESPs
local activeESP = {}

-- ESP function
local function createESP(player, character)
    local humanoid = character:WaitForChild("Humanoid")
    local rootPart = character:WaitForChild("HumanoidRootPart") -- Position reference

    -- Create labels
    local textLabel = Drawing.new("Text")
    textLabel.Visible = false
    textLabel.Center = true
    textLabel.Outline = false
    textLabel.Font = 3
    textLabel.Size = 11
    textLabel.Color = Color3.new(1, 1, 1) -- White ("Distance:")

    local distanceLabel = Drawing.new("Text")
    distanceLabel.Visible = false
    distanceLabel.Center = true
    distanceLabel.Outline = false
    distanceLabel.Font = 3
    distanceLabel.Size = 11
    distanceLabel.Color = Color3.new(1, 0.5, 0) -- Orange (distance)

    local connectionRender, connectionAncestry, connectionHealth

    local function removeESP()
        textLabel.Visible = false
        textLabel:Remove()
        distanceLabel.Visible = false
        distanceLabel:Remove()
        if connectionRender then connectionRender:Disconnect() end
        if connectionAncestry then connectionAncestry:Disconnect() end
        if connectionHealth then connectionHealth:Disconnect() end
    end

    connectionAncestry = character.AncestryChanged:Connect(function(_, parent)
        if not parent then
            removeESP()
        end
    end)

    connectionHealth = humanoid.HealthChanged:Connect(function(health)
        if health <= 0 or humanoid:GetState() == Enum.HumanoidStateType.Dead then
            removeESP()
        end
    end)

    connectionRender = runService.RenderStepped:Connect(function()
        local position, onScreen = camera:WorldToViewportPoint(rootPart.Position)
        if onScreen then
            -- Calculate distance
            local distance = (localPlayer.Character.HumanoidRootPart.Position - rootPart.Position).Magnitude
            -- Update "Distance:" text
            textLabel.Position = Vector2.new(position.X, position.Y + 39) -- 39 pixels down
            textLabel.Text = "Distance:"
            textLabel.Visible = true

            -- Update distance value next to "Distance:"
            distanceLabel.Position = Vector2.new(position.X + textLabel.TextBounds.X + 5, position.Y + 39)
            distanceLabel.Text = string.format("%.1f", distance) -- Round distance
            distanceLabel.Visible = true
        else
            textLabel.Visible = false
            distanceLabel.Visible = false
        end
    end)

    -- Store connections for cleanup
    activeESP[player] = {textLabel, distanceLabel, connectionRender, connectionAncestry, connectionHealth}
end

-- Function to handle new players
local function handleNewPlayer(player)
    if player.Character then
        createESP(player, player.Character)
    end
    player.CharacterAdded:Connect(function(character)
        createESP(player, character)
    end)
end

-- Cleanup function for all ESPs
local function cleanupESP()
    for player, espData in pairs(activeESP) do
        espData[1]:Remove() -- Remove textLabel
        espData[2]:Remove() -- Remove distanceLabel
        for i = 3, #espData do
            espData[i]:Disconnect() -- Disconnect all connections
        end
    end
    activeESP = {}
end

-- ESP Toggle
local espEnabled = false

local function toggleESP(state)
    espEnabled = state
    if espEnabled then
        -- Add ESP for all current players
        for _, player in pairs(players:GetPlayers()) do
            if player ~= localPlayer then
                handleNewPlayer(player)
            end
        end
        -- Listen for new players
        players.PlayerAdded:Connect(handleNewPlayer)
    else
        -- Remove all ESPs
        cleanupESP()
    end
end

-- Example toggle setup
ESPSection:AddToggle({
    Name = "Distance ESP",
    Value = false,
    Flag = "distance_esp_toggle",
    Callback = function(state)
        toggleESP(state)
    end,
})

local atmEspEnabled = false
local atmConnections = {}

local function toggleESPForATM(state)
    local ATMFolder = game.Workspace:FindFirstChild("Map"):FindFirstChild("ATMS")
    if not ATMFolder then
        Library.Notify({
            Text = "The 'ATM' folder does not exist in the Workspace.",
            Duration = 2
        })
        return
    end

    if state then
        -- Enable ESP
        for _, object in ipairs(ATMFolder:GetChildren()) do
            if object:IsA("BasePart") and not object:FindFirstChild("BillboardGui") then
                local BillboardGui = Instance.new("BillboardGui")
                local TextLabel = Instance.new("TextLabel")

                BillboardGui.Adornee = object
                BillboardGui.Size = UDim2.new(0, 100, 0, 50)
                BillboardGui.AlwaysOnTop = true

                TextLabel.Parent = BillboardGui
                TextLabel.Size = UDim2.new(1, 0, 1, 0)
                TextLabel.BackgroundTransparency = 1
                TextLabel.Text = "ATM"
                TextLabel.TextColor3 = Color3.new(0, 1, 0)
                TextLabel.TextScaled = true

                BillboardGui.Parent = object
                table.insert(atmConnections, BillboardGui)
            end
        end
    else
        -- Disable ESP
        for _, gui in ipairs(atmConnections) do
            if gui.Parent then
                gui:Destroy()
            end
        end
        atmConnections = {}
    end
end

-- Adding the toggle to ESPSection
ESPSection:AddToggle({
    Name = 'ATM ESP',
    Value = false,
    Flag = 'ATMESP',
    Locked = false,
    Callback = function(state)
        atmEspEnabled = state
        toggleESPForATM(atmEspEnabled)
    end,
})


local player = game:GetService("Players").LocalPlayer
local camera = game:GetService("Workspace").CurrentCamera

local ESPObjects = {} -- Store ESP objects per player
local ESPEnabled = false -- Track ESP toggle state

-- ESP settings
local Settings = {
    Box_Color = Color3.fromRGB(255, 255, 255),
    Box_Thickness = 1,
}

-- ESP object creation functions
local function NewQuad(thickness, color)
    local quad = Drawing.new("Quad")
    quad.Visible = false
    quad.PointA = Vector2.new(0, 0)
    quad.PointB = Vector2.new(0, 0)
    quad.PointC = Vector2.new(0, 0)
    quad.PointD = Vector2.new(0, 0)
    quad.Color = color
    quad.Filled = false
    quad.Thickness = thickness
    return quad
end

-- Update visibility for a player’s ESP elements
local function Visibility(state, library)
    for _, obj in pairs(library) do
        obj.Visible = state
    end
end

local function CreateESP(plr)
    if ESPObjects[plr] then return end -- Prevent duplicates

    local library = {
        black = NewQuad(Settings.Box_Thickness * 2, Color3.fromRGB(0, 0, 0)),
        box = NewQuad(Settings.Box_Thickness, Settings.Box_Color),
    }
    ESPObjects[plr] = library

    local function UpdateESP()
        local connection
        connection = game:GetService("RunService").RenderStepped:Connect(function()
            if ESPEnabled and plr.Character and plr.Character:FindFirstChild("Humanoid") and plr.Character:FindFirstChild("HumanoidRootPart") and plr.Character.Humanoid.Health > 0 then
                local HumPos, OnScreen = camera:WorldToViewportPoint(plr.Character.HumanoidRootPart.Position)
                if OnScreen then
                    local head = camera:WorldToViewportPoint(plr.Character.Head.Position)
                    local DistanceY = math.clamp((Vector2.new(head.X, head.Y) - Vector2.new(HumPos.X, HumPos.Y)).magnitude, 2, math.huge)

                    local function Size(item)
                        item.PointA = Vector2.new(HumPos.X + DistanceY, HumPos.Y - DistanceY * 2)
                        item.PointB = Vector2.new(HumPos.X - DistanceY, HumPos.Y - DistanceY * 2)
                        item.PointC = Vector2.new(HumPos.X - DistanceY, HumPos.Y + DistanceY * 2)
                        item.PointD = Vector2.new(HumPos.X + DistanceY, HumPos.Y + DistanceY * 2)
                    end
                    Size(library.box)
                    Size(library.black)

                    Visibility(true, library)
                else
                    Visibility(false, library)
                end
            else
                Visibility(false, library)
                if not game.Players:FindFirstChild(plr.Name) then
                    connection:Disconnect()
                end
            end
        end)
    end
    coroutine.wrap(UpdateESP)()
end

-- Toggle ESP for all players
local function ToggleESP(state)
    ESPEnabled = state
    if ESPEnabled then
        for _, plr in pairs(game:GetService("Players"):GetPlayers()) do
            if plr ~= player then
                CreateESP(plr)
            end
        end
        game:GetService("Players").PlayerAdded:Connect(function(plr)
            if plr ~= player then
                CreateESP(plr)
            end
        end)
    else
        for _, objects in pairs(ESPObjects) do
            Visibility(false, objects)
        end
    end
end

-- Add toggle to Pepsi UI
ESPSection:AddToggle({
    Name = 'Box ESP',
    Value = false,
    Flag = 'esp_toggle',
    Locked = false,
    Callback = function(state)
        ToggleESP(state)
    end,
})




-- Preview: https://cdn.discordapp.com/attachments/796378086446333984/818089455897542687/unknown.png
-- Made by Blissful#4992

local ESPEnabled = false -- Global toggle for health ESP

local Settings = {
    Box_Color = Color3.fromRGB(255, 0, 0),
    Tracer_Color = Color3.fromRGB(255, 0, 0),
    Tracer_Thickness = 1,
    Box_Thickness = 1,
    Tracer_Origin = "Bottom", -- Middle or Bottom if FollowMouse is on this won't matter...
    Tracer_FollowMouse = false,
    Tracers = false
}

local Team_Check = {
    TeamCheck = false, -- if TeamColor is on this won't matter...
    Green = Color3.fromRGB(0, 255, 0),
    Red = Color3.fromRGB(255, 0, 0)
}

local TeamColor = true

--// SEPARATION
local player = game:GetService("Players").LocalPlayer
local camera = game:GetService("Workspace").CurrentCamera
local mouse = player:GetMouse()

local function NewQuad(thickness, color)
    local quad = Drawing.new("Quad")
    quad.Visible = false
    quad.PointA = Vector2.new(0, 0)
    quad.PointB = Vector2.new(0, 0)
    quad.PointC = Vector2.new(0, 0)
    quad.PointD = Vector2.new(0, 0)
    quad.Color = color
    quad.Filled = false
    quad.Thickness = thickness
    quad.Transparency = 1
    return quad
end

local function NewLine(thickness, color)
    local line = Drawing.new("Line")
    line.Visible = false
    line.From = Vector2.new(0, 0)
    line.To = Vector2.new(0, 0)
    line.Color = color
    line.Thickness = thickness
    line.Transparency = 1
    return line
end

local function Visibility(state, lib)
    for _, x in pairs(lib) do
        x.Visible = state
    end
end

local function ToColor3(col)
    local r = col.r
    local g = col.g
    local b = col.b
    return Color3.new(r, g, b)
end

local black = Color3.fromRGB(0, 0, 0)
local function ESP(plr)
    local library = {
        blacktracer = NewLine(Settings.Tracer_Thickness * 2, black),
        tracer = NewLine(Settings.Tracer_Thickness, Settings.Tracer_Color),
        black = NewQuad(Settings.Box_Thickness * 2, black),
        box = NewQuad(Settings.Box_Thickness, Settings.Box_Color),
        healthbar = NewLine(3, black),
        greenhealth = NewLine(1.5, black)
    }

    local function Colorize(color)
        for _, x in pairs(library) do
            if x ~= library.healthbar and x ~= library.greenhealth and x ~= library.blacktracer and x ~= library.black then
                x.Color = color
            end
        end
    end

    local function Updater()
        local connection
        connection = game:GetService("RunService").RenderStepped:Connect(function()
            if not ESPEnabled then
                Visibility(false, library)
                return
            end

            if plr.Character and plr.Character:FindFirstChild("Humanoid") and plr.Character:FindFirstChild("HumanoidRootPart") and plr.Character.Humanoid.Health > 0 and plr.Character:FindFirstChild("Head") then
                local HumPos, OnScreen = camera:WorldToViewportPoint(plr.Character.HumanoidRootPart.Position)
                if OnScreen then
                    local head = camera:WorldToViewportPoint(plr.Character.Head.Position)
                    local DistanceY = math.clamp((Vector2.new(head.X, head.Y) - Vector2.new(HumPos.X, HumPos.Y)).magnitude, 2, math.huge)

                    -- Tracer
                    if Settings.Tracers then
                        if Settings.Tracer_Origin == "Middle" then
                            library.tracer.From = camera.ViewportSize * 0.5
                            library.blacktracer.From = camera.ViewportSize * 0.5
                        elseif Settings.Tracer_Origin == "Bottom" then
                            library.tracer.From = Vector2.new(camera.ViewportSize.X * 0.5, camera.ViewportSize.Y)
                            library.blacktracer.From = Vector2.new(camera.ViewportSize.X * 0.5, camera.ViewportSize.Y)
                        end
                        if Settings.Tracer_FollowMouse then
                            library.tracer.From = Vector2.new(mouse.X, mouse.Y + 36)
                            library.blacktracer.From = Vector2.new(mouse.X, mouse.Y + 36)
                        end
                        library.tracer.To = Vector2.new(HumPos.X, HumPos.Y + DistanceY * 2)
                        library.blacktracer.To = Vector2.new(HumPos.X, HumPos.Y + DistanceY * 2)
                    else
                        Visibility(false, library)
                    end

                    -- Health Bar
                    local d = (Vector2.new(HumPos.X - DistanceY, HumPos.Y - DistanceY * 2) - Vector2.new(HumPos.X - DistanceY, HumPos.Y + DistanceY * 2)).magnitude
                    local healthoffset = plr.Character.Humanoid.Health / plr.Character.Humanoid.MaxHealth * d

                    library.greenhealth.From = Vector2.new(HumPos.X - DistanceY - 4, HumPos.Y + DistanceY * 2)
                    library.greenhealth.To = Vector2.new(HumPos.X - DistanceY - 4, HumPos.Y + DistanceY * 2 - healthoffset)

                    library.healthbar.From = Vector2.new(HumPos.X - DistanceY - 4, HumPos.Y + DistanceY * 2)
                    library.healthbar.To = Vector2.new(HumPos.X - DistanceY - 4, HumPos.Y - DistanceY * 2)

                    library.greenhealth.Color = Color3.fromRGB(255, 0, 0):lerp(Color3.fromRGB(0, 255, 0), plr.Character.Humanoid.Health / plr.Character.Humanoid.MaxHealth)

                    if Team_Check.TeamCheck then
                        if plr.TeamColor == player.TeamColor then
                            Colorize(Team_Check.Green)
                        else
                            Colorize(Team_Check.Red)
                        end
                    else
                        library.tracer.Color = Settings.Tracer_Color
                        library.box.Color = Settings.Box_Color
                    end

                    if TeamColor then
                        Colorize(plr.TeamColor.Color)
                    end

                    Visibility(true, library)
                else
                    Visibility(false, library)
                end
            else
                Visibility(false, library)
                if not game.Players:FindFirstChild(plr.Name) then
                    connection:Disconnect()
                end
            end
        end)
    end

    coroutine.wrap(Updater)()
end

for _, v in pairs(game:GetService("Players"):GetPlayers()) do
    if v.Name ~= player.Name then
        coroutine.wrap(ESP)(v)
    end
end

game.Players.PlayerAdded:Connect(function(newplr)
    if newplr.Name ~= player.Name then
        coroutine.wrap(ESP)(newplr)
    end
end)

-- Add Toggle for ESP
ESPSection:AddToggle({
    Name = 'Health ESP',
    Value = false,
    Flag = 'health_esp_toggle',
    Locked = false,
    Callback = function(state)
        ESPEnabled = state
    end,
})

local excludedItems = {"Phone", "Fist", "Extended Clip", "Water", "Black Gloves",  "Standard Clip", "Speed Loader", "Heavy Magazine", "Drum Magazine", "Card", "Fake ID", "Hot Chips", "Empty Bag", "Rice Bag", "Medium Rice Ball Bag", "Large Rice Ball Bag", "Small Rice Ball Bag", "Baking Soda", "Surgical Mask", "Black Surgical Mask", "Ski Mask", "Mask", "Crate", "Box", "Flour", "Potato"}

-- Check if an item is excluded
local function isExcluded(itemName)
    for _, excluded in ipairs(excludedItems) do
        if itemName == excluded then
            return true
        end
    end
    return false
end

-- Update size and boldness based on distance
local function updateSizeAndBoldness(billboardGui, player)
    local localPlayer = game.Players.LocalPlayer
    local character = localPlayer.Character
    if not character then return end
    local head = character:FindFirstChild("Head")
    if not head then return end

    local targetHead = player.Character and player.Character:FindFirstChild("Head")
    if not targetHead then return end

    local distance = (head.Position - targetHead.Position).Magnitude
    local minSize = 6
    local maxSize = 16
    local sizeFactor = math.clamp((150 / distance), 0.2, 2)
    local scaledTextSize = maxSize * sizeFactor

    if billboardGui:FindFirstChild("TextLabel") then
        local textLabel = billboardGui:FindFirstChild("TextLabel")
        textLabel.TextSize = math.clamp(scaledTextSize, minSize, maxSize)
        local boldFactor = math.clamp((150 / distance), 1, 3)
        textLabel.Font = (boldFactor > 2) and Enum.Font.SourceSansBold or Enum.Font.SourceSans
    end
end

-- Inventory display function
local function displayInventory(player)
    local character = player.Character or player.CharacterAdded:Wait()
    local head = character:WaitForChild("Head")

    local billboardGui = Instance.new("BillboardGui")
    billboardGui.Name = "InventoryESP"
    billboardGui.Adornee = head
    billboardGui.Size = UDim2.new(0, 150, 0, 100)
    billboardGui.StudsOffset = Vector3.new(0, 6, 0)
    billboardGui.AlwaysOnTop = true

    local textLabel = Instance.new("TextLabel", billboardGui)
    textLabel.Size = UDim2.new(1, 0, 1, 0)
    textLabel.TextColor3 = Color3.fromRGB(255, 165, 0)
    textLabel.BackgroundTransparency = 1
    textLabel.TextSize = 16
    textLabel.Font = Enum.Font.SourceSansBold
    textLabel.TextWrapped = true

    local function updateInventory()
        local inventoryText = ""
        local displayedItems = {}

        for _, item in pairs(player.Backpack:GetChildren()) do
            if not isExcluded(item.Name) and not displayedItems[item.Name] then
                inventoryText = item.Name .. "\n" .. inventoryText
                displayedItems[item.Name] = true
            end
        end

        local tool = character:FindFirstChildOfClass("Tool")
        if tool and not isExcluded(tool.Name) then
            inventoryText = tool.Name .. " -Hand\n" .. inventoryText
        end

        textLabel.Text = inventoryText
    end

    player.Backpack.ChildAdded:Connect(updateInventory)
    player.Backpack.ChildRemoved:Connect(updateInventory)
    character.ChildAdded:Connect(updateInventory)
    character.ChildRemoved:Connect(updateInventory)

    game:GetService("RunService").RenderStepped:Connect(function()
        if billboardGui and billboardGui.Parent then
            updateSizeAndBoldness(billboardGui, player)
        end
    end)

    updateInventory()
    billboardGui.Parent = head
end

local espEnabled = false

local function toggleESP()
    if espEnabled then
        for _, player in pairs(game:GetService("Players"):GetPlayers()) do
            if player ~= game:GetService("Players").LocalPlayer then
                player.CharacterAdded:Connect(function(character)
                    displayInventory(player)
                end)

                if player.Character then
                    displayInventory(player)
                end
            end
        end
    else
        for _, player in pairs(game:GetService("Players"):GetPlayers()) do
            if player.Character then
                local head = player.Character:FindFirstChild("Head")
                if head then
                    local existingGui = head:FindFirstChild("InventoryESP")
                    if existingGui then
                        existingGui:Destroy()
                    end
                end
            end
        end
    end
end

ESPSection:AddToggle({
    Name = 'Inventory ESP',
    Value = false,
    Flag = 'invesp',
    Locked = false,
    Callback = function(value)
        espEnabled = value -- Directly set the state based on the toggle value
        toggleESP() -- Run the ESP toggle logic
    end,
})
local Players = game:GetService("Players")
local localPlayer = Players.LocalPlayer
local highlightESPEnabled = false -- Boolean to track if ESP is enabled
local highlights = {} -- Store highlights for players
local highlightColor = Color3.new(0, 0, 0) -- Default highlight color

-- Function to create Highlight for a player
local function CreateHighlight(player)
    if highlights[player] or player == localPlayer then return end -- Prevent duplicate highlights or highlighting the local player

    local highlight = Instance.new("Highlight")
    highlight.Name = "HighlightESP"
    highlight.FillTransparency = 0.5
    highlight.FillColor = highlightColor -- Use the selected highlight color
    highlight.OutlineColor = Color3.new(1, 1, 1) -- White outline
    highlight.OutlineTransparency = 0
    highlight.Parent = player.Character or player.CharacterAdded:Wait()
    highlights[player] = highlight
end

-- Function to remove Highlight from a player
local function RemoveHighlight(player)
    if highlights[player] then
        highlights[player]:Destroy()
        highlights[player] = nil
    end
end

-- Enable Highlight ESP for all players
local function EnableHighlightESP()
    for _, player in pairs(Players:GetPlayers()) do
        CreateHighlight(player)
    end
end

-- Disable Highlight ESP for all players
local function DisableHighlightESP()
    for player, _ in pairs(highlights) do
        RemoveHighlight(player)
    end
end

-- Toggle Highlight ESP
local function ToggleHighlightESP(state)
    highlightESPEnabled = state
    if highlightESPEnabled then
        EnableHighlightESP()
    else
        DisableHighlightESP()
    end
end

-- Update highlight colors dynamically
local function UpdateHighlightColors()
    for player, highlight in pairs(highlights) do
        highlight.FillColor = highlightColor
    end
end

-- Listen for players joining and leaving
Players.PlayerAdded:Connect(function(player)
    if highlightESPEnabled then
        CreateHighlight(player)
    end
end)

Players.PlayerRemoving:Connect(function(player)
    RemoveHighlight(player)
end)

-- UI Setup (example using a UI library)
ESPSection:AddToggle({
    Name = "Highlight ESP",
    Value = false,
    Flag = "highlight_esp_toggle",
    Callback = function(state)
        ToggleHighlightESP(state)
    end
})



ESPSection:AddColorPicker({
    Name = "Highlight Color",
    Default = highlightColor,
    Flag = "highlight_color_picker",
    Callback = function(color)
        highlightColor = color
        if highlightESPEnabled then
            UpdateHighlightColors()
        end
    end
})




local ServerSection = GeneralTab:CreateSection({
    Name = 'Server Settings',
    Side = 'Left'
})

local Button = ServerSection:AddButton({
    Name = "FPS Boost",
    Callback = function()
    --[[
	WARNING: Heads up! This script has not been verified by ScriptBlox. Use at your own risk!
]]
_G.Ignore = {}
_G.Settings = {
	Players = {
		["Ignore Me"] = true,
		["Ignore Others"] = true,
		["Ignore Tools"] = true
	},
	Meshes = {
		NoMesh = false,
		NoTexture = false,
		Destroy = false
	},
	Images = {
		Invisible = true,
		Destroy = false
	},
	Explosions = {
		Smaller = true,
		Invisible = false, -- Not for PVP games
		Destroy = false -- Not for PVP games
	},
	Particles = {
		Invisible = true,
		Destroy = false
	},
	TextLabels = {
		LowerQuality = true,
		Invisible = false,
		Destroy = false
	},
	MeshParts = {
		LowerQuality = true,
		Invisible = false,
		NoTexture = false,
		NoMesh = false,
		Destroy = false
	},
	Other = {
		["FPS Cap"] = 360, -- true to uncap
		["No Camera Effects"] = true,
		["No Clothes"] = true,
		["Low Water Graphics"] = true,
		["No Shadows"] = true,
		["Low Rendering"] = true,
		["Low Quality Parts"] = true,
		["Low Quality Models"] = true,
		["Reset Materials"] = true,
	}
}
loadstring(game:HttpGet("https://raw.githubusercontent.com/CasperFlyModz/discord.gg-rips/main/FPSBooster.lua"))()
    end
})

local Button = ServerSection:AddButton({
    Name = "Server Hop",
    Callback = function()
     loadstring(game:HttpGet(('https://raw.githubusercontent.com/Morples/Server-hop/refs/heads/main/Script'), true))()
    end
})

local Button = ServerSection:AddButton({
    Name = "Rejoin Server",
    Callback = function()
     local TeleportService = game:GetService("TeleportService")
    local Players = game:GetService("Players")
    local LocalPlayer = Players.LocalPlayer

    local Rejoin = coroutine.create(function()
        local Success, ErrorMessage = pcall(function()
            TeleportService:Teleport(game.PlaceId, LocalPlayer)
        end)

        if ErrorMessage and not Success then
            warn(ErrorMessage)
        end
    end)

    coroutine.resume(Rejoin)
    end
})

local Button = ServerSection:AddButton({
    Name = "Join Lowest Server",
    Callback = function()
    local Http = game:GetService("HttpService")
    local TPS = game:GetService("TeleportService")
    local Api = "https://games.roblox.com/v1/games/"

    local _place = game.PlaceId
    local _servers = Api.._place.."/servers/Public?sortOrder=Asc&limit=100"
    function ListServers(cursor)
        local Raw = game:HttpGet(_servers .. ((cursor and "&cursor="..cursor) or ""))
        return Http:JSONDecode(Raw)
    end

    local Server, Next; repeat
        local Servers = ListServers(Next)
        Server = Servers.data[1]
        Next = Servers.nextPageCursor
    until Server

    TPS:TeleportToPlaceInstance(_place, Server.id, game.Players.LocalPlayer)
    end
})

local Button = ServerSection:AddButton({
    Name = "Anti Afk",
    Callback = function()
    loadstring(game:HttpGet(('https://pastebin.com/raw/DtwLVRdP'), true))()
    end
})

local Button = ServerSection:AddButton({
    Name = "Always Day | Buggy",
    Callback = function()
    loadstring(game:HttpGet(('https://pastebin.com/raw/LVpCeksT'), true))()
    end
})

local Button = ServerSection:AddButton({
    Name = "Full bright",
    Callback = function()
     loadstring(game:HttpGet(('https://pastebin.com/raw/ZdyDttMz'), true))()
    end
})

local Button = ServerSection:AddButton({
    Name = "RTX",
    Callback = function()
     loadstring(game:HttpGet(('https://pastebin.com/raw/1wWNeSSC'), true))()
    end
})

local Button = ServerSection:AddButton({
    Name = "Ping Spoofer",
    Callback = function()
     loadstring(game:HttpGet(('https://pastebin.com/raw/JFCSs34K'), true))()
    end
})

local PlayerTab = Window:CreateTab({
    Name = 'Player'
})

local PlayerSection = PlayerTab:CreateSection({
    Name = 'Player Options',
    Side = 'Left'
})

local Button = PlayerSection:AddButton({
    Name = "Insta-Interact",
    Callback = function()
         for i,v in pairs(game:GetService("Workspace"):GetDescendants()) do
         if v:IsA("ProximityPrompt") then
            v["HoldDuration"] = 0
         end
      end
      game:GetService("ProximityPromptService").PromptButtonHoldBegan:Connect(function(v)
         v["HoldDuration"] = 0
      end)
    end
})

local Camera = workspace.CurrentCamera
local runService = game:GetService("RunService")

local stretchResEnabled = false -- Tracks the toggle state
local stretchConnection -- Stores the RenderStepped connection

local Toggle = PlayerSection:AddToggle({
    Name = 'Stretch Res',
    Value = false,
    Flag = 'stretchres',
    Locked = false,
    Callback = function(state)
        stretchResEnabled = state

        if stretchResEnabled then
            -- Enable Stretch Resolution
            getgenv().Resolution = {
                [".gg/scripters"] = 0.65 -- Adjust vertical stretching factor
            }

            -- Start stretching the camera
            if not stretchConnection then
                stretchConnection = runService.RenderStepped:Connect(function()
                    Camera.CFrame = Camera.CFrame * CFrame.new(0, 0, 0, 1, 0, 0, 0, getgenv().Resolution[".gg/scripters"], 0, 0, 0, 1)
                end)
            end
        else
            -- Disable Stretch Resolution
            if stretchConnection then
                stretchConnection:Disconnect()
                stretchConnection = nil
            end
        end
    end
})

local Toggle = PlayerSection:AddToggle({
    Name = 'Enable Reset Button',
    Value = false, -- Default state for the reset button (enabled)
    Flag = 'resetbutton',
    Locked = false,
    Callback = function(state)
        -- Enable or disable the Reset Button
        game:GetService("CoreGui"):SetCore("ResetButtonCallback", state and true or false)
    end
})

local WalkspeedSection = PlayerTab:CreateSection({
    Name = 'Walkspeed Options',
    Side = 'Right'
})

local SpeedSlider = WalkspeedSection:AddSlider({
    Name = 'Adjust WS',
    Flag = "SpeedFster",
    Value = 12,
    Min = 0,
    Max = 23,
    Decimals = 1,
    llegalInput = false,
    Callback = function(value)
       local player = game.Players.LocalPlayer
        local humanoid = player.Character and player.Character:FindFirstChild("Humanoid")
        
        if humanoid then
            humanoid.WalkSpeed = value  -- Update walk speed based on slider value
        end
    end
})

local FOVSection = PlayerTab:CreateSection({
    Name = 'Fov Options',
    Side = 'Right'
})

local FOVSlider = FOVSection:AddSlider({
    Name = 'Adjust FOV',
    Flag = "BegFOV",
    Value = 70,
    Min = 70,
    Max = 120,
    Decimals = 1,
    llegalInput = false,
    Callback = function(value)
       workspace.CurrentCamera.FieldOfView = value
    end
})

local SpooferrSection = PlayerTab:CreateSection({
    Name = 'Spoofer (CLIENT-SIDED)',
    Side = 'Left'
})

local Toggle = SpooferrSection:AddToggle({
    Name = 'Spoof Enabled',
    Value = false,
    Flag = 'spoofenbaled',
    Locked = false,
    Callback = function(Value)
        spoofEnabled = Value

        -- Lock or unlock textboxes based on toggle state
        TextBoxName:SetLocked(not spoofEnabled)
        TextBoxUsername:SetLocked(not spoofEnabled)

    end
})

-- Textbox for "Set Name"
local TextBoxName = SpooferrSection:AddTextbox({
    Name = 'Set Name',
    Flag = "setname",
    Value = "blue.cc",
    Locked = false, -- Initially locked since "Spoof Enabled" is false
    Callback = function(Value)
        if spoofEnabled then
            updateName(Value)
        end
    end
})

-- Textbox for "Set Username"
local TextBoxUsername = SpooferrSection:AddTextbox({
    Name = 'Set Username',
    Flag = "setusername",
    Value = "blue.cc",
    Locked = false, -- Initially locked since "Spoof Enabled" is false
    Callback = function(Value)
        if spoofEnabled then
            updateUsername(Value)
        end
    end
})





local GunSection = GeneralTab:CreateSection({
    Name = 'Gun Mods (WAVE ONLY inf ammo works with xeno)',
    Side = 'Right'
})

local Players = game:GetService("Players")


local isToggled = false


local function continuouslyUpdateWeaponStats(player)
    while isToggled do 
        local backpack = player:FindFirstChild("Backpack")
        if backpack then
            -- Loop through all items in the backpack
            for _, item in ipairs(backpack:GetChildren()) do
                if item:IsA("Tool") then 
                     if item:FindFirstChild("Ammo") and item:FindFirstChild("Mag") then
                        item.Ammo.Value = 18
                        item.Mag.Value = 10
                    end
                end
            end
        end
        wait(0) 
    end
end


local Toggle = GunSection:AddToggle({
    Name = "Inf Ammo ",
    Value = false,
    Flag = "WeaponStatsToggle", 
    Callback = function(Value)
        isToggled = Value 
        if isToggled then
            
            for _, player in ipairs(Players:GetPlayers()) do
                task.spawn(function()
                    continuouslyUpdateWeaponStats(player)
                end)
            end
        end
    end,
})


Players.PlayerAdded:Connect(function(player)
    player.CharacterAdded:Connect(function()
        if isToggled then
            task.spawn(function()
                continuouslyUpdateWeaponStats(player)
            end)
        end
    end)
end)


if isToggled then
    for _, player in ipairs(Players:GetPlayers()) do
        task.spawn(function()
            continuouslyUpdateWeaponStats(player)
        end)
    end
end

local Players = game:GetService("Players")
local localPlayer = Players.LocalPlayer
local toggleEnabled = false -- Variable to store the state of the toggle
local fireRateValue = 0.147 -- Default fire rate value controlled by the slider

-- Function to enable one-shot with adjustable fire rate
local function enableOneShot(tool)
    if tool:IsA("Tool") then
        local settingModule = tool:FindFirstChild("Setting")
        
        if settingModule and settingModule:IsA("ModuleScript") then
            local success, settings = pcall(require, settingModule)

            if success and type(settings) == "table" and settings.BaseDamage ~= nil then
                settings.FireRate = fireRateValue -- Use the slider's fire rate value
                settings.Auto = true -- Enable rapid fire
            else
                print("")
            end
        else
            print("")
        end
    end
end

-- Function to disable one-shot (reset settings)
local function disableOneShot(tool)
    if tool:IsA("Tool") then
        local settingModule = tool:FindFirstChild("Setting")
        
        if settingModule and settingModule:IsA("ModuleScript") then
            local success, settings = pcall(require, settingModule)

            if success and type(settings) == "table" and settings.BaseDamage ~= nil then
                settings.FireRate = 0.147 -- Reset to default fire rate
                settings.Auto = false -- Disable rapid fire
            else
                print("")
            end
        else
            print("")
        end
    end
end

-- Monitor equipped tools
local function onCharacterAdded(character)
    character.ChildAdded:Connect(function(child)
        if child:IsA("Tool") then
            if toggleEnabled then
                enableOneShot(child)
            else
                disableOneShot(child)
            end
        end
    end)

    -- Check for tools that may already be equipped
    for _, child in ipairs(character:GetChildren()) do
        if child:IsA("Tool") then
            if toggleEnabled then
                enableOneShot(child)
            else
                disableOneShot(child)
            end
        end
    end
end

-- Setup for the local player
if localPlayer.Character then
    onCharacterAdded(localPlayer.Character)
end

localPlayer.CharacterAdded:Connect(onCharacterAdded)

-- Toggle button logic
local Toggle = GunSection:AddToggle({
    Name = 'Rapid Fire',
    Value = false,
    Flag = 'rafire',
    Locked = false,
    Callback = function(Value)
        toggleEnabled = Value

        -- Re-enable or disable one-shot based on the toggle state
        if localPlayer.Character then
            for _, child in ipairs(localPlayer.Character:GetChildren()) do
                if child:IsA("Tool") then
                    if toggleEnabled then
                        enableOneShot(child)
                    else
                        disableOneShot(child)
                    end
                end
            end
        end
    end
})

-- Slider logic to adjust fire rate
local Slider = GunSection:AddSlider({
    Name = 'Firerate Settingsr',
    Flag = "sliderRate",
    Value = 0.147, -- Default value
    Min = 0.03, -- Minimum value
    Max = 0.147, -- Maximum value
    Decimals = 3, -- Number of decimals allowed
    Callback = function(Value)
        fireRateValue = Value -- Update the fire rate dynamically
        print("")

        -- Apply the updated fire rate if toggle is enabled
        if toggleEnabled and localPlayer.Character then
            for _, child in ipairs(localPlayer.Character:GetChildren()) do
                if child:IsA("Tool") then
                    enableOneShot(child)
                end
            end
        end
    end
})

local Players = game:GetService("Players")
local localPlayer = Players.LocalPlayer
local toggleEnabled = false -- Variable to store the state of the toggle

-- Function to enable quick reload by modifying ReloadTime
local function quickReloadEnabled(tool)
    if tool:IsA("Tool") then
        local settingModule = tool:FindFirstChild("Setting")
        
        if settingModule and settingModule:IsA("ModuleScript") then
            local success, settings = pcall(require, settingModule)

            if success and type(settings) == "table" and settings.ReloadTime ~= nil then
                settings.ReloadTime = 0 -- Set to modified value
            else
                print("")
            end
        else
            print("")
        end
    end
end

-- Function to reset ReloadTime (Quick Reload)
local function quickReload(tool)
    if tool:IsA("Tool") then
        local settingModule = tool:FindFirstChild("Setting")
        
        if settingModule and settingModule:IsA("ModuleScript") then
            local success, settings = pcall(require, settingModule)

            if success and type(settings) == "table" and settings.ReloadTime ~= nil then
                settings.ReloadTime = 2.9 -- Reset to default value
            else
                print("")
            end
        else
            print("")
        end
    end
end

-- Monitor equipped tools
local function onCharacterAdded(character)
    character.ChildAdded:Connect(function(child)
        if child:IsA("Tool") then
            if toggleEnabled then
                quickReloadEnabled(child)
            else
                quickReload(child)
            end
        end
    end)

    -- Check for tools that may already be equipped
    for _, child in ipairs(character:GetChildren()) do
        if child:IsA("Tool") then
            if toggleEnabled then
                quickReloadEnabled(child)
            else
                quickReload(child)
            end
        end
    end
end

-- Setup for the local player
if localPlayer.Character then
    onCharacterAdded(localPlayer.Character)
end

localPlayer.CharacterAdded:Connect(onCharacterAdded)

-- Toggle button logic
local Toggle = GunSection:AddToggle({
    Name = 'Quick Reload',
    Value = false,
    Flag = 'quickfire',
    Locked = false,
    Callback = function(Value)
        toggleEnabled = Value

        -- Re-enable or disable quick reload based on the toggle state
        if localPlayer.Character then
            for _, child in ipairs(localPlayer.Character:GetChildren()) do
                if child:IsA("Tool") then
                    if toggleEnabled then
                        quickReloadEnabled(child)
                    else
                        quickReload(child)
                    end
                end
            end
        end
    end
})

local Players = game:GetService("Players")
local localPlayer = Players.LocalPlayer
local toggleEnabled = false -- Variable to store the state of the toggle

-- Table to store default values for each setting
local defaultSettings = {}

-- Function to enable modifications (e.g., quick aim adjustments)
local function enableModifications(tool)
    if tool:IsA("Tool") then
        local settingModule = tool:FindFirstChild("Setting")

        if settingModule and settingModule:IsA("ModuleScript") then
            local success, settings = pcall(require, settingModule)

            if success and type(settings) == "table" then
                -- Save default values if not already saved
                if not defaultSettings[tool.Name] then
                    defaultSettings[tool.Name] = {
                        Accuracy = settings.Accuracy,
                        SpreadX = settings.SpreadX,
                        SpreadY = settings.SpreadY,
                        Range = settings.Range,
                        Recoil = settings.Recoil
                    }
                end

                -- Modify settings
                settings.Accuracy = 1
                settings.SpreadX = 0
                settings.SpreadY = 0
                settings.Range = 50000
                settings.Recoil = 0
            else
                print("")
            end
        else
            print("")
        end
    end
end

-- Function to reset settings to their defaults
local function resetToDefaults(tool)
    if tool:IsA("Tool") then
        local settingModule = tool:FindFirstChild("Setting")

        if settingModule and settingModule:IsA("ModuleScript") then
            local success, settings = pcall(require, settingModule)

            if success and type(settings) == "table" and defaultSettings[tool.Name] then
                -- Reset settings to their saved default values
                local defaults = defaultSettings[tool.Name]
                settings.Accuracy = defaults.Accuracy
                settings.SpreadX = defaults.SpreadX
                settings.SpreadY = defaults.SpreadY
                settings.Range = defaults.Range
                settings.Recoil = defaults.Recoil
            else
                print("")
            end
        else
            print("")
        end
    end
end

-- Monitor equipped tools
local function onCharacterAdded(character)
    character.ChildAdded:Connect(function(child)
        if child:IsA("Tool") then
            if toggleEnabled then
                enableModifications(child)
            else
                resetToDefaults(child)
            end
        end
    end)

    -- Check for tools that may already be equipped
    for _, child in ipairs(character:GetChildren()) do
        if child:IsA("Tool") then
            if toggleEnabled then
                enableModifications(child)
            else
                resetToDefaults(child)
            end
        end
    end
end

-- Setup for the local player
if localPlayer.Character then
    onCharacterAdded(localPlayer.Character)
end

localPlayer.CharacterAdded:Connect(onCharacterAdded)

-- Toggle button logic
local Toggle = GunSection:AddToggle({
    Name = '0 Recoil',
    Value = false,
    Flag = 'quickaim',
    Locked = false,
    Callback = function(Value)
        toggleEnabled = Value

        -- Enable or reset settings based on toggle state
        if localPlayer.Character then
            for _, child in ipairs(localPlayer.Character:GetChildren()) do
                if child:IsA("Tool") then
                    if toggleEnabled then
                        enableModifications(child)
                    else
                        resetToDefaults(child)
                    end
                end
            end
        end
    end
})

AutoSection:AddToggle({
    Name = 'ATM status',
    Value = false,          -- Default state
    Flag = 'feature_toggle', -- Unique identifier
    Locked = false,         -- Prevent user changes
    Callback = function(state)
        local player = game.Players.LocalPlayer
        local screenGui = player:FindFirstChild("PlayerGui"):FindFirstChild("ATMStatusGUI")

        if state then
            if not screenGui then
                screenGui = Instance.new("ScreenGui")
                screenGui.Name = "ATMStatusGUI"
                screenGui.Parent = player:WaitForChild("PlayerGui")

                local frame = Instance.new("Frame")
                frame.Size = UDim2.new(0, 300, 0, 400)
                frame.Position = UDim2.new(1, -320, 0.5, -200)
                frame.BackgroundColor3 = Color3.fromRGB(20, 20, 20)
                frame.BackgroundTransparency = 0.2
                frame.BorderSizePixel = 0
                frame.Parent = screenGui

                local corner = Instance.new("UICorner")
                corner.CornerRadius = UDim.new(0, 10)
                corner.Parent = frame

                local shadow = Instance.new("ImageLabel")
                shadow.AnchorPoint = Vector2.new(0.5, 0.5)
                shadow.Position = UDim2.new(0.5, 0, 0.5, 5)
                shadow.Size = UDim2.new(1, 40, 1, 40)
                shadow.BackgroundTransparency = 1
                shadow.Image = "rbxassetid://1316045217"  
                shadow.ImageTransparency = 0.7
                shadow.ZIndex = -1
                shadow.Parent = frame

                local title = Instance.new("TextLabel")
                title.Size = UDim2.new(1, 0, 0, 40)
                title.BackgroundTransparency = 1
                title.Text = "ATM Status"
                title.TextColor3 = Color3.fromRGB(255, 255, 255)
                title.TextScaled = true
                title.Font = Enum.Font.GothamBold
                title.TextStrokeTransparency = 0.75
                title.Parent = frame

                local titleGradient = Instance.new("UIGradient")
                titleGradient.Color = ColorSequence.new{
                    ColorSequenceKeypoint.new(0, Color3.fromRGB(255, 255, 255)),
                    ColorSequenceKeypoint.new(1, Color3.fromRGB(200, 200, 200))
                }
                titleGradient.Rotation = 90
                titleGradient.Parent = title

                local scrollingFrame = Instance.new("ScrollingFrame")
                scrollingFrame.Size = UDim2.new(1, -10, 1, -50)
                scrollingFrame.Position = UDim2.new(0, 5, 0, 45)
                scrollingFrame.BackgroundTransparency = 1
                scrollingFrame.ScrollBarThickness = 8
                scrollingFrame.ScrollBarImageColor3 = Color3.fromRGB(120, 120, 120)
                scrollingFrame.Parent = frame

                local uiListLayout = Instance.new("UIListLayout")
                uiListLayout.Parent = scrollingFrame
                uiListLayout.SortOrder = Enum.SortOrder.LayoutOrder
                uiListLayout.HorizontalAlignment = Enum.HorizontalAlignment.Center
                uiListLayout.VerticalAlignment = Enum.VerticalAlignment.Top
                uiListLayout.Padding = UDim.new(0, 5)

                local function updateATMStatus()
                    for _, child in ipairs(scrollingFrame:GetChildren()) do
                        if child:IsA("TextLabel") then
                            child:Destroy()
                        end
                    end

                    local ATMS = game:GetService("Workspace").Map:WaitForChild("ATMS")
                    local labels = {}

                    for i = 1, 15 do
                        local atmName = "ATM: " .. i
                        local atm = ATMS:FindFirstChild("ATM" .. i)

                        if atm then
                            local attachment = atm:FindFirstChild("Attachment")
                            if attachment then
                                local proximityPrompt = attachment:FindFirstChild("ProximityPrompt")
                                local textColor = Color3.fromRGB(255, 0, 0) 
                                if proximityPrompt and proximityPrompt.Enabled then
                                    textColor = Color3.fromRGB(0, 255, 0)  
                                end

                                local textLabel = Instance.new("TextLabel")
                                textLabel.Size = UDim2.new(1, -20, 0, 25)
                                textLabel.BackgroundTransparency = 0.1
                                textLabel.BackgroundColor3 = Color3.fromRGB(30, 30, 30)
                                textLabel.Text = atmName
                                textLabel.TextColor3 = textColor 
                                textLabel.TextScaled = true
                                textLabel.Font = Enum.Font.Gotham
                                textLabel.TextXAlignment = Enum.TextXAlignment.Left
                                textLabel.TextYAlignment = Enum.TextYAlignment.Center
                                textLabel.Parent = scrollingFrame

                                local labelCorner = Instance.new("UICorner")
                                labelCorner.CornerRadius = UDim.new(0, 6)
                                labelCorner.Parent = textLabel

                                local labelGradient = Instance.new("UIGradient")
                                labelGradient.Color = ColorSequence.new{
                                    ColorSequenceKeypoint.new(0, Color3.fromRGB(60, 60, 60)),
                                    ColorSequenceKeypoint.new(1, Color3.fromRGB(80, 80, 80))
                                }
                                labelGradient.Rotation = 90
                                labelGradient.Parent = textLabel
                                
                                table.insert(labels, textLabel)
                            end
                        end
                    end

                    local contentHeight = #labels * 30  
                    scrollingFrame.CanvasSize = UDim2.new(0, 0, 0, contentHeight)
                end

                updateATMStatus()

                local connection
                connection = game:GetService("RunService").Heartbeat:Connect(function()
                    if state then
                        updateATMStatus()
                    else
                        if connection then connection:Disconnect() end
                    end
                end)
            end
        else
            if screenGui then
                screenGui:Destroy()
            end
        end
    end
})

AutoSection:AddButton({
    Name = 'big head',
    Callback = function()
		-- Big Heads/ Hitbox Script
for k,v in next, game:GetService('Players'):GetChildren() do 
oghead = v.Character:FindFirstChild('Head')
if oghead then 
oghead.Size = Vector3.new(2, 2, 2) 
game.Players.LocalPlayer.Character.Head.Size = Vector3.new(1, 1, 1)

end
end
    end
})

ServerSection:AddButton({
    Name = 'Infinite Zoom',
    Callback = function()
        getgenv().host = game:GetService'Players'.LocalPlayer

        host.CameraMaxZoomDistance = math.huge
    end
})

AutoSection:AddButton({
    Name = 'Faster rapid fire',
    Callback = function()
        local Players = game:GetService("Players")
-- Function to enable one-shot
local function enableOneShot(tool)
    if tool:IsA("Tool") then
        local settingModule = tool:FindFirstChild("Setting")

        if settingModule and settingModule:IsA("ModuleScript") then
            local success, settings = pcall(require, settingModule)

            if success and type(settings) == "table" and settings.FireRate ~= nil then
                settings.Auto = true;
                settings.FireRate = 0.07;
                setting.ReloadTime = 0;
                setting.Accuracy = 1;
                setting.SpreadX = 0;
                setting.SpreadY = 0;
                setting.Range = 50000;
                setting.JamChance = 0;
                setting.CameraRecoilingEnabled = false;
                setting.Recoil = 0;
                print("god mode activated.")
            else
                print("The 'Setting' module is invalid or does not contain 'BaseDamage'.")
            end
        else
            print("This tool does not have a 'Setting' module.")
        end
    end
end

-- Monitor equipped tools
local function onCharacterAdded(character)
    character.ChildAdded:Connect(function(child)
        if child:IsA("Tool") then
            enableOneShot(child)
        end
    end)

    -- Check for tools that may already be equipped
    for _, child in ipairs(character:GetChildren()) do
        if child:IsA("Tool") then
            enableOneShot(child)
        end
    end
end

-- Setup for the local player
local localPlayer = Players.LocalPlayer

if localPlayer.Character then
    onCharacterAdded(localPlayer.Character)
end

localPlayer.CharacterAdded:Connect(onCharacterAdded)
    end
})

AutoSection:AddButton({
    Name = 'Enable ATMS',
    Callback = function()
        local function enableProximityPrompt(prompt)
            if prompt then
                prompt.Enabled = state
            end
        end

        local atmNames = {
            "ATM1", "ATM2", "ATM3", "ATM4", "ATM5",
            "ATM6", "ATM7", "ATM8", "ATM9", "ATM10",
            "ATM11", "ATM12", "ATM13", "ATM14", "ATM15"
        }

        for _, atmName in ipairs(atmNames) do
            local atm = workspace.Map.ATMS:FindFirstChild(atmName)
            if atm then
                local proximityPrompt = atm:FindFirstChild("Attachment"):FindFirstChild("ProximityPrompt")
                enableProximityPrompt(proximityPrompt)
            end
        end
    end
})

AutoSection:AddButton({
    Name = 'tp active ATM',
    Callback = function()
        local player = game.Players.LocalPlayer
        local character = player.Character or player.CharacterAdded:Wait()
        local humanoidRootPart = character:WaitForChild("HumanoidRootPart")
        local camera = workspace.CurrentCamera

        local ATMS = {
            {name = "ATM1", cframe = CFrame.new(-33.1487, 3.7370, -299.5453), path = "ATM1"},
            {name = "ATM2", cframe = CFrame.new(538.4818, 3.7371, -349.0415), path = "ATM2"},
            {name = "ATM3", cframe = CFrame.new(497.8156, 3.7839, 405.5681), path = "ATM3"},
            {name = "ATM4", cframe = CFrame.new(236.1748, 3.1180, -165.3973), path = "ATM4"},
            {name = "ATM5", cframe = CFrame.new(-652.0219, 4.2857, 155.1690), path = "ATM5"},
            {name = "ATM6", cframe = CFrame.new(-455.1304, 4.3107, 370.8311), path = "ATM6"},
            {name = "ATM7", cframe = CFrame.new(-266.3022, 4.4058, -212.2364), path = "ATM7"},
            {name = "ATM8", cframe = CFrame.new(-10.4940, 3.7371, 233.9844), path = "ATM8"},
            {name = "ATM9", cframe = CFrame.new(717.0417, 3.8176, 413.7101), path = "ATM9"},
            {name = "ATM10", cframe = CFrame.new(-536.8209, 4.2857, -20.3541), path = "ATM10"},
            {name = "ATM11", cframe = CFrame.new(-652.021, 4.285, 155.169), path = "ATM11"},
            {name = "ATM12", cframe = CFrame.new(714.4320, 4.2857, -240.3657), path = "ATM12"},
            {name = "ATM13", cframe = CFrame.new(-314.9244, 3.8715, 145.9376), path = "ATM13"},
            {name = "ATM14", cframe = CFrame.new(-377.9388, 4.3107, -359.7116), path = "ATM14"},
            {name = "ATM15", cframe = CFrame.new(360.0960, 3.7371, -359.4165), path = "ATM15"},
        }

        for _, atm in ipairs(ATMS) do
            local atmPath = workspace:FindFirstChild("Map"):FindFirstChild("ATMS"):FindFirstChild(atm.path)
            if atmPath and atmPath:FindFirstChild("Attachment") then
                local proximityPrompt = atmPath.Attachment:FindFirstChild("ProximityPrompt")
                if proximityPrompt and proximityPrompt.Enabled then
                    
                    humanoidRootPart.CFrame = atm.cframe
                    
                    local cameraOffset = Vector3.new(0, 5, -10) 
                    camera.CFrame = CFrame.new(humanoidRootPart.Position + cameraOffset, atm.cframe.Position)

                    wait(0.5)
                    
                    fireproximityprompt(proximityPrompt, 1, true)
                    
                    return
                end
            end
        end
    end
})

AutoSection:AddButton({
    Name = 'OPfinality',
    Callback = function()
       loadstring(game:HttpGet("https://raw.githubusercontent.com/melvin123gp/yo-mam/refs/heads/main/yo%20mam"))()() 
    end
})
