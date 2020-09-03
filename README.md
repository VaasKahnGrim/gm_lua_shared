# gm_lua_shared
Grant access to the entire Lua/C API for use in creating new modules that fully take advantage of the Lua/C API


# How to Use
Put #include"lua_shared.cpp" into your file where you need the LuaC functions at and then simply use it.

Be sure to consult the lua manuals for Lua 5.1/Lua 5.2/Lua 5.3/Lua 5.4/LuaJIT


# Notice
Some shit might not work right off the bat, some things might be missing from here that are needed.

This might also not have the FULL FULL LuaC API available. You can thank paranoid people for forcing Facepunch's hand and removing it. 
But just about everything exported by lua_shared is available in this thing. I don't feel that its my place to tell you what is or is not a safety risk nor is it my job to tell you what you can and can not use.

I am also not responsible for what ever you use this thing for, I will likely judge you for it however. But if somebody does something stupid or malicious DO NOT come crying to me about it. If its stupid, help them unfuck their shit. If its malicious, call the FBI or something. But don't bother me with such concerns, because I won't be lifting a finger to do anything about either of those things. I WILL fix issues with this thing over time and expand it as needed when ever something new becomes available. I will also look into any pull requests that arise

If you have an issue make a pullrequest with the needed fix. The stuff in this thing is pretty simple after you do some reading with the docs so chances are you can easily fix any issue that might come up. I say this because I don't even use 90% of the stuff available in the LuaC API to begin with so I've not bothered testing every function to make sure they all work. I've simply just setup linking to them all as best I could and defining various things such lua_State* that most of the functions need. You may also need to do some leg work if you use other things such as garrysmod_common as there could be conflicts possibly.
