<h3><a href="https://codeforces.com/contest/1867/problem/C" target="_blank" rel="noopener noreferrer">Salyg1n and the MEX Game</a></h3>

<div class="header"><div class="title">C. Salyg1n and the MEX Game</div><div class="time-limit"><div class="property-title">time limit per test</div>3 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p><span class="tex-font-style-bf">This is an interactive problem!</span></p><p>salyg1n gave Alice a set $$$S$$$ of $$$n$$$ distinct integers $$$s_1, s_2, \ldots, s_n$$$ ($$$0 \leq s_i \leq 10^9$$$). Alice decided to play a game with this set against Bob. The rules of the game are as follows:</p><ul> <li> Players take turns, with Alice going first.<p> </p></li><li> In one move, Alice adds one number $$$x$$$ ($$$0 \leq x \leq 10^9$$$) to the set $$$S$$$. The set $$$S$$$ must not contain the number $$$x$$$ at the time of the move.</li><li> In one move, Bob removes one number $$$y$$$ from the set $$$S$$$. The set $$$S$$$ must contain the number $$$y$$$ at the time of the move. Additionally, the number $$$y$$$ must be <span class="tex-font-style-bf">strictly smaller</span> than the last number added by Alice.</li><li> The game ends when Bob cannot make a move or after $$$2 \cdot n + 1$$$ moves (in which case Alice's move will be the last one).</li><li> The result of the game is $$$\operatorname{MEX}\dagger(S)$$$ ($$$S$$$ at the end of the game).</li><li> Alice aims to maximize the result, while Bob aims to minimize it. </li></ul><p>Let $$$R$$$ be the result when both players play optimally. <span class="tex-font-style-bf">In this problem, you play as Alice against the jury program playing as Bob.</span> Your task is to implement a strategy for Alice such that the result of the game is always at least $$$R$$$.</p><p>$$$\dagger$$$ $$$\operatorname{MEX}$$$ of a set of integers $$$c_1, c_2, \ldots, c_k$$$ is defined as the smallest non-negative integer $$$x$$$ which does not occur in the set $$$c$$$. For example, $$$\operatorname{MEX}(\{0, 1, 2, 4\})$$$ $$$=$$$ $$$3$$$.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains an integer $$$t$$$ ($$$1 \leq t \leq 10^5$$$) - the number of test cases.</p></div><div><div class="section-title">Interaction</div><p>The interaction between your program and the jury program begins with reading an integer $$$n$$$ ($$$1 \leq n \leq 10^5$$$) - the size of the set $$$S$$$ before the start of the game.</p><p>Then, read one line - $$$n$$$ distinct integers $$$s_i$$$ $$$(0 \leq s_1  \lt  s_2  \lt  \ldots  \lt  s_n \leq 10^9)$$$ - the set $$$S$$$ given to Alice.</p><p>To make a move, output an integer $$$x$$$ ($$$0 \leq x \leq 10^9$$$) - the number you want to add to the set $$$S$$$. $$$S$$$ must not contain $$$x$$$ at the time of the move. Then, read one integer $$$y$$$ $$$(-2 \leq y \leq 10^9)$$$. </p><ul> <li> If $$$0 \leq y \leq 10^9$$$ - Bob removes the number $$$y$$$ from the set $$$S$$$. It's your turn!</li><li> If $$$y$$$ $$$=$$$ $$$-1$$$ - the game is over. After this, proceed to handle the next test case or terminate the program if it was the last test case.</li><li> Otherwise, $$$y$$$ $$$=$$$ $$$-2$$$. This means that you made an invalid query. Your program should immediately terminate to receive the verdict <span class="tex-font-style-tt">Wrong Answer</span>. Otherwise, it may receive any other verdict. </li></ul><p>After printing a query do not forget to output the end of line and flush the output. Otherwise, you will get <span class="tex-font-style-tt">Idleness limit exceeded</span>. To do this, use:</p><ul><li> <span class="tex-font-style-tt">fflush(stdout)</span> or <span class="tex-font-style-tt">cout.flush()</span> in C++;</li><li> <span class="tex-font-style-tt">System.out.flush()</span> in Java;</li><li> <span class="tex-font-style-tt">flush(output)</span> in Pascal;</li><li> <span class="tex-font-style-tt">stdout.flush()</span> in Python;</li><li> see the documentation for other languages.</li></ul> It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$10^5$$$.<p><span class="tex-font-style-bf">Do not attempt to hack this problem.</span></p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id008641887814960302" id="id008082837418560067" class="input-output-copier">Copy</div></div><pre id="id008641887814960302">3
5
1 2 3 5 7

7

5

-1

3
0 1 2

0

-1

3
5 7 57

-1</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id001119741273478847" id="id009977470846748385" class="input-output-copier">Copy</div></div><pre id="id001119741273478847">8

57

0

3

0

0</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first test case, the set $$$S$$$ changed as follows:</p><p>{$$$1, 2, 3, 5, 7$$$} $$$\to$$$ {$$$1, 2, 3, 5, 7, 8$$$} $$$\to$$$ {$$$1, 2, 3, 5, 8$$$} $$$\to$$$ {$$$1, 2, 3, 5, 8, 57$$$} $$$\to$$$ {$$$1, 2, 3, 8, 57$$$} $$$\to$$$ {$$$0, 1, 2, 3, 8, 57$$$}. In the end of the game, $$$\operatorname{MEX}(S) = 4$$$, $$$R = 4$$$.</p><p>In the second test case, the set $$$S$$$ changed as follows:</p><p>{$$$0, 1, 2$$$} $$$\to$$$ {$$$0, 1, 2, 3$$$} $$$\to$$$ {$$$1, 2, 3$$$} $$$\to$$$ {$$$0, 1, 2, 3$$$}. In the end of the game, $$$\operatorname{MEX}(S) = 4$$$, $$$R = 4$$$.</p><p>In the third test case, the set $$$S$$$ changed as follows:</p><p>{$$$5, 7, 57$$$} $$$\to$$$ {$$$0, 5, 7, 57$$$}. In the end of the game, $$$\operatorname{MEX}(S) = 1$$$, $$$R = 1$$$.</p></div>