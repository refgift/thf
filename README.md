# thf - Thief Eliminator

- runs on Linux.
- Uses a perceptron detector and applies a reality change to "ghost" them.

## Build
- Use the included makefile with the make utility and a C compiler.
- make install will copy to /usr/local/bin to make it available. You
  need "sudo make install" to access the target directory.

## Run
- It prints dots and bangs. Dots are detect loops, bangs are applies.
  They are commented out with // that can be taken out to enable them
  and then you will see if the detects and applies are happening. Some
  applies will fail due to the timing delay of the printouts. 
- If you add the program to systemd, having the print out will cause
   heavy system use by the journaller daemon. Comment out the putchar() 
   for each or remove them if you set it up as a service.

## Rationale
- Killing Thieves was a King's practice and law in the Sumerian Kingdom.
  He burn them, drown them or whatever he felt necessary. It is still law
  worldwide as far as I can tell. If you let it happen, it will. I have
  noticed that software thieves die by drowning, naturally. And car
  thieves die of fire, naturally. Naturally, I thought, but I looked 
  at laws and found that the law to kill murderers, theives and adulterers
  was engrafted in clay with cuniforms and still exists as code. Is is
  netural or law of man?

