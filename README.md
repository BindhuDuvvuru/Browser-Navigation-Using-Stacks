Advanced Browser Navigation System Using Stacks

Language: C  
Course: Data Structures Mini Project

Project Overview:
This project simulates the Back and Forward page navigation system of a web browser using the Stack data structure. 
By using two stacks (Back and Forward), the program behaves like real browsers such as Chrome and Edge.
The project also includes advanced features like bookmarks, searching history, exporting history, clearing history, and file handling.

Features:
• Visit new website
• Back navigation using stack
• Forward navigation using stack
• Add bookmark
• View bookmarks
• Search browsing history
• Reopen last closed page
• Export browsing history to a text file
• Clear browsing history
• Auto save browsing session using file handling
• Auto restore session on restart

Why Stack?
Browser navigation depends on the LIFO (Last In First Out) principle.
When Back is used, the most recently visited page must open first → Stack is the correct data structure.

How to compile and run:
gcc browser.c -o browser
./browser

Files in this project:
• browser.c – Main source code
• session.bin – Auto-saved session (generated automatically)
• BrowsingHistory.txt – Exported history report

Sample Output:
Current Page: Snapchat
Back History: YouTube → Home
Forward History: None
'Snapchat' added to Bookmarks
Browsing history exported successfully

Important Viva Points:
• Two stacks are used: one for Back and one for Forward
• When a new website is visited, Forward history is cleared
• Back = Pop from Back stack + Push to Forward stack
• Forward = Pop from Forward stack + Push to Back stack
• File handling is used to restore state on next program run

Future Enhancements:
• Multiple tabs system
• Private browsing mode
• Time spent per website
• Graphical user interface

Conclusion:
This project shows that the Stack data structure is the most suitable choice for implementing Back and Forward web page navigation. 
With added features like bookmarks, search, export, and auto session restore, this project closely simulates real browser behavior.
