#PThread Programming Tutorial
##Description
The tutorial includes ***concepts, motivations and design considerations*** for using Pthread, the major
part of which could be divided into **Thread Management**, **Mutex Variables**, **Condition Variables**.

###Definition
- **Linux Process**: contain information about program resources and program execution state, including:    
    - Process ID, process groupID, user ID and group ID
    - Environment, Working Dir
    - Program Instructions
    - Registers, Stack, Heap
    - File descriptors
    - Signal actions
    - Shared Libraries
    - Inter-process Tools: message queues, pipes, semaphores or shared memory

- **Thread**: an independent stream of instructions, scheduled to run by Operating System. A thread
 has its own: stack pointer, registers, scheduling properties(policy or priority), set of pending and 
 blocked signals, thread specific data.

##References
- [PThread Progamming](https://computing.llnl.gov/tutorials/pthreads/)