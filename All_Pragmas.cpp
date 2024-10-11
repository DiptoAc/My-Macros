#pragma GCC optimize("O3,unroll-loops,inline,fast-math,no-stack-protector")
#pragma GCC target("avx2,popcnt,sse4.2")
#pragma GCC diagnostic ignored "-Wnarrowing"
#pragma GCC diagnostic ignored "-Wunused-variable"
 
#pragma GCC optimize("lto,tree-vectorize,inline-functions-called-once,reorder-blocks,split-loops,split-paths,move-loop-invariants")
#pragma GCC target_clones("avx2", "sse4.2", "default")
#pragma GCC target("tune=native")
