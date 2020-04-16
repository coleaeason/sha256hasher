# sha256hasher

Simple multi-threaded CLI tool written in C++ for creating SHA256 hashes from a file of new line separated items.

Build it:
```
make
```

Use it:
```ShellSession
# Print usage
localhost->sha256hasher (master) > ./sha256hasher
Usage:
./sha256hasher -file <filename> -threads <threads to use>
Example: ./sha256hasher -file text.file -threads 8

# Hash something
localhost->sha256hasher (master) > ./sha256hasher -file test.file
B94D27B9934D3E08A52E52D7DA7DABFAC484EFE37A5380EE9088F7ACE2EFCDE9

# Hash something with a non-default thread count
localhost->sha256hasher (master) > ./sha256hasher -file test.file -threads 9
B94D27B9934D3E08A52E52D7DA7DABFAC484EFE37A5380EE9088F7ACE2EFCDE9
19581E27DE7CED00FF1CE50B2047E7A567C76B1CBAEBABE5EF03F7C3017BB5B7
4A44DC15364204A80FE80E9039455CC1608281820FE2B24F1E5233ADE6AF1DD5
4FC82B26AECB47D2868C4EFBE3581732A3E7CBCC6C2EFB32062C08170A05EEB8
6B51D431DF5D7F141CBECECCF79EDF3DD861C3B4069F0B11661A3EEFACBBA918
EF2D127DE37B942BAAD06145E54B0C619A1F22327B2EBBCFBEC78F5564AFE39D
E7F6C011776E8DB7CD330B54174FD76F7D0216B612387A5FFCFB81E6F0919683
7902699BE42C8A8E46FBBB4501726517E86B22C56A189F7625A6DA49081B2451
2C624232CDD221771294DFBB310ACA000A0DF6AC8B66B696D90EF06FDEFB64A3
6B86B273FF34FCE19D6B804EFF5A3F5747ADA4EAA22F1D49C01E52DDB7875B4B
D4735E3A265E16EEE03F59718B9B5D03019C07D8B6C51F90DA3A666EEC13AB35
4E07408562BEDB8B60CE05C1DECFE3AD16B72230967DE01F640B7E4729B49FCE
4B227777D4DD1FC61C6F884F48641D02B4D121D3FD328CB08B5531FCACDABF8A
```
