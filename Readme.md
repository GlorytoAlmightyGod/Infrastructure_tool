# Infrastructure tool

Pre-Requisites
  - Any Linux platform with **C++ & Bash**
  - Functions only for non-root users

Functions/Features
  - Scans all the mounted Drives( including Windows Users folder) and home folders in running system recursively and then displays the top 10 files which have the largest size on the system!
  - Classifies Desktop files on the basis of file formats and rearranges them into respective folders in Documents!
  - One can select file extensions to be rearranged in the '**formats**' file!
  - User can customize number of top files with largest size he/she wants to see by just changing value in the file '**top_files_number**'.
  - (**NOT RECOMMENDED**) One can choose to give permissions to access folders with root owner by just adding '**sudo**' in every find command present in every script! 

How to Use?
  - Navigate to the folder where you copied the files. Grant permissions to the file named '**infra_tool**' for execution as a script by running "**chmod +x infra_tool**".
  - Wait and Watch in the terminal window.
