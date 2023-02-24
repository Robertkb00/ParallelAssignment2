# ParallelAssignment2: The Minotaur

## 1. Minotaur's Birthday Party

In order to keep track of every person in the party, a thread will need to be created for each attendee. Each attendee will be assigned two states, 'hungry' and 'full'. Each attendee will start as 'hungry', and when they are called they will get a cupcake and become 'full'. When an attendee is 'full', they will no longer ask for a cupcake. This makes it so that no attendee will ask for a second cupcake. That way, once one cupcake has been given out for each attendee, we know everyone has gotten one.

## 2. Minotaur's Crystal Vase.

This problem has three methods of going about it.

Method 1: Simply leave the door as is. This will require people to have to repeatedly check whether or not the door is open, which can cause a lot of extra wasted time.

Method 2: Leave a sign. If the sign is busy, come back later. If not go on in, and the sign changes. This method allows people to see if it's busy and come back later without waiting around.

Method 3: Have them for a line. This will allow the people to form an orderly line and see it as soon as possible, but it also allows people to get back IN line.

I opted for Method 2, as Methods 1 and 3 can cause the people/threads to really bunch together. Each thread will have a toggle for whether or not a person is 'smiling', they start smiling after they see the vase. Once everyone is smiling, we know everyone has seen the vase.
