# Building DOSLib for AutoCAD 2026 and 2027

This fork builds the ObjectARX module for two AutoCAD releases. The public repo includes all source needed to build; only the Autodesk ObjectARX SDK is required on your machine (not stored in git). Release modules are build outputs under `bin\Release\arx\` and are not committed.

Upstream DOSLib no longer publishes binaries for recent AutoCAD versions, so building from this tree is the supported path.

| AutoCAD | ObjectARX SDK | Configuration | Output |
|---|---|---|---|
| 2027 | 26 | `Release_ARX26` | `DOSLib26x64.arx` |
| 2026 | 25 | `Release_ARX25` | `DOSLib25x64.arx` |

## Requirements

- Visual Studio 2026 Build Tools with the C++ workload, ATL, and MFC. Both `Release_ARX26` and `Release_ARX25` use the `v145` toolset. Supported releases are AutoCAD 2027 and AutoCAD 2026.1.2 or later.
- ObjectARX SDK for each target release, unpacked to `<root>\acad\arx\<nn>`, where `<root>` is the drive root. The project refers to `\acad\arx\25` and `\acad\arx\26`.
  - ObjectARX 2027: `\acad\arx\26`
  - ObjectARX 2026: `\acad\arx\25`
  - Download from Autodesk Platform Services (requires an Autodesk login and license acceptance). Do not commit the SDK.

## Build

Solution: `make\make_doslib.sln`. Project: `source\DOSLib.vcxproj`.

```bash
msbuild source\DOSLib.vcxproj /p:Configuration=Release_ARX26 /p:Platform=x64
msbuild source\DOSLib.vcxproj /p:Configuration=Release_ARX25 /p:Platform=x64
```

Successful builds write the module to a version folder under `bin\Release\arx\`: `2027\DOSLib26x64.arx` for AutoCAD 2027, and `2026.1.2\DOSLib25x64.arx` for AutoCAD 2026.1.2 or later. Intermediate files land under `source\x64\` and `bin\`; both are listed in `.gitignore` so a clean clone stays small and you always rebuild against your installed SDK.

## Loading

The `ptsimport.lsp` loader expects `DOSLib<nn>x64.arx`, where `<nn>` is the first two characters of AutoCAD's `ACADVER`. Copy the output for the running AutoCAD release onto the AutoCAD support path.

## Fixes in this fork

- `Release_ARX26` defined `ARX25` instead of `ARX26` (`source\DOSLib.vcxproj`, line 1204). That made `_ARX_VER` evaluate to 25 in the 2027 build. The definition is now `ARX26`.

## Attribution

DOSLib is by Dale Fugier and Robert McNeel & Associates, MIT licensed (see `LICENSE`). This fork adds AutoCAD 2026 and 2027 build configurations and documentation. The DOSLib trademark is held by Robert McNeel & Associates.
