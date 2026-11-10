# DOSLib for AutoCAD 2026 and 2027

A maintained build of **DOSLib**, a library of LISP-callable functions for AutoCAD that fill gaps in AutoCAD's built-in AutoLISP, such as file dialogs, file and folder utilities, and color conversion.

The original DOSLib by Dale Fugier is no longer maintained, and no binaries are published for recent AutoCAD releases. This fork builds the ObjectARX module for **AutoCAD 2027** (ObjectARX SDK 26) and **AutoCAD 2026** (ObjectARX SDK 25) from source.

> This is an unofficial fork. DOSLib is a trademark of Robert McNeel & Associates, who do not endorse or support this fork.

## Prebuilt binaries

You don't need to compile to use DOSLib for AutoCAD 2027. The built module is in the repo:

- `arx/2027/DOSLib26x64.arx` (SHA256 `3c98b20618c538365581dffb4532d9aa5d19dc3f019e485ef786be8d96a833f5`)

Copy it to an AutoCAD support folder, for example `%APPDATA%\Autodesk\AutoCAD 2027\R26.0\enu\Support`. A 2026 build will be added to `arx/2026/` once it's verified.

Build from source if you need a different AutoCAD release or want to change DOSLib.

## Quick start

1. Install Visual Studio 2026 Build Tools with the C++ workload, ATL, and MFC, plus the v143 and v145 toolsets.
2. Download the ObjectARX SDK for your AutoCAD release from Autodesk Platform Services and unpack it to `\acad\arx\25` (2026) or `\acad\arx\26` (2027) at the drive root.
3. Build:

   ```bash
   msbuild source\DOSLib.vcxproj /p:Configuration=Release_ARX26 /p:Platform=x64
   msbuild source\DOSLib.vcxproj /p:Configuration=Release_ARX25 /p:Platform=x64
   ```

4. Copy `bin\Release\arx\DOSLib26x64.arx` (2027) or `DOSLib25x64.arx` (2026) to an AutoCAD support folder.

See [BUILDING.md](BUILDING.md) for the full build, toolset, and layout details.

## Using DOSLib

Load the module with `ARXLOAD` or by putting the `.arx` on the support path and loading it from AutoLISP:

```lisp
(arxload "DOSLib26x64.arx")
```

Functions are named `dos_*`. Example from a working command:

```lisp
(setq fname (dos_getfiled "Select a file" "C:\\" "PTS files (*.pts)|*.pts||"))
```

## Example: PTS point-cloud import

The PTS import command for AutoCAD uses DOSLib for its file dialog, file size, and RGB-to-ACI color mapping. It imports ReCap `.pts` files as colored POINT entities.

- Product page: [truevis.com/pts-import](https://truevis.com/pts-import/)
- Autodesk App Store: [marketplace.autodesk.com](https://marketplace.autodesk.com/apps/466a254c-dcf0-44d8-96c0-300b4323f60b)

## What changed from upstream

- **AutoCAD 2027 target:** `Release_ARX26` builds `DOSLib26x64.arx`.
- **AutoCAD 2026 target:** `Release_ARX25` builds `DOSLib25x64.arx`.
- **Fix:** the `Release_ARX26` configuration defined `ARX25` instead of `ARX26`. That made `_ARX_VER` evaluate to 25 in the 2027 build. It is now `ARX26`.
- **Docs:** `BUILDING.md` covers the build and SDK layout for both releases.

The upstream history is preserved.

## License

MIT License. See [LICENSE](LICENSE). The original copyright (Robert McNeel & Associates, 1992–2026) is retained, and changes in this fork are offered under the same license.

## Credits

- Original DOSLib: Dale Fugier, Robert McNeel & Associates.
- AutoCAD 2026/2027 build and maintenance: truevis.
