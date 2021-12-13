# Cobalt-Clip

Cobalt-clip is clipboard addons for cobaltstrike to interact with clipboard. With this you can dump, edit and monitor the content of q clipboard.

# How to use

You load clipmon.cna in your cobaltstrike and you have 3 new commands :
- dumpclip : Dump the content of the clipboard and send the output to an operator
- set-clipboard-data : Change the content of a clipboard
- clipmon : Monitor the clipboard. For each clipboard updated, you have the content of the clipboard, the current window and the date with hours.
⚠️ clipmon is reflective dll launched as post-exploitation jobs with bdllspawn function (.cna script). cobaltstrike have a buffer to receive output of reflective dll, you don't receive it directly.

# Compilation information

For dumpclip and set-clipboard-data.
Iis Beacon Object Files, you have a .sh script to compil in x64. 
For clipmon.
It was made on visualstudio. the source code was based on : https://github.com/stephenfewer/ReflectiveDLLInjection.

# Credits

Thanks to @MeltraActor (https://twitter.com/meltraactor)  and @Sh0ckFR (https://twitter.com/sh0ckfr) for advise 
