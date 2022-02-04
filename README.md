# Cobalt-Clip

Cobalt-Clip is clipboard add-on for Cobalt Strike to interact with the victim's clipboard. With Cobalt-Clip you can dump, edit and monitor the content of a clipboard.

# How to use

Load clipmon.cna in Cobalt Strike to get 3 new commands :
- dumpclip : Dump the clipboard's content and send the output to an operator.
- set-clipboard-data : Modify the content of a victim's clipboard.
- clipmon : Monitor the clipboard. When the clipboard is updated, you receive the contents of the clipboard, the current window and the date with hours.
⚠️ clipmon is a reflective dll launched as a post-exploitation job with the bdllspawn function (.cna script). Cobalt Strike has a buffer to receive output from the reflective dll. You don't receive it directly.

# Compilation information

For dumpclip and set-clipboard-data:\
IIS Beacon Object Files, you have a .sh script to compil in x64.\
\
For clipmon:\
It was made in Visual Studio. The source code was based on : https://github.com/stephenfewer/ReflectiveDLLInjection.

# Credits

Thanks to @MeltraActor (https://twitter.com/meltraactor)  and @Sh0ckFR (https://twitter.com/sh0ckfr) for advise 
