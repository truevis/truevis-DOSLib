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

The full function reference is in [docs/functions](docs/functions/README.md): all 316 `dos_*` functions, with syntax, parameters, return values, and examples.

## Tested in AutoCAD 2027

Checked in AutoCAD 2027 with `DOSLib26x64.arx` loaded:

- **Module loaded:** `dos_arxlist` lists `doslib26x64.arx`.

  ![DOSLib listed in the loaded ARX modules](docs/images/arx-loaded-check.jpg)

- **File size:** `dos_filesize` on the 5,114,241-byte sample `Pump_points_exported_from_ReCap.pts` returns `(("Pump_points_exported_from_ReCap.pts" . 5114241))`.
- **Tokenizing:** `dos_strtokens "1 2 3" " "` returns `(1 2 3)`.

  ![dos_filesize and dos_strtokens results in AutoCAD 2027](docs/images/dos-filesize-strtokens.jpg)

- **Color conversion:** `dos_rgbtoaci` maps `(255 0 0)` to ACI 1 (red) and `(0 255 0)` to ACI 3 (green). `dos_acitorgb 1` returns `(255 0 0)`.

### Dialogs and pop-ups

These DOSLib functions open standard Windows dialogs from AutoLISP, with results returned to your code:

- **`dos_msgbox`:** shows a message box with the Information icon and an OK button. Clicking OK returns `4`, as documented.

  ![dos_msgbox message box in AutoCAD 2027](docs/images/gui-msgbox.jpg)

- **`dos_listbox`:** shows a list of pump parts. Choosing "Intake" and clicking OK returns `"Intake"`.

  ![dos_listbox dialog in AutoCAD 2027](docs/images/gui-listbox.jpg)

- **`dos_getcolor`:** opens the Windows color picker, starting at ACI 1. Clicking Cancel returns `nil`. Choosing a color with OK was not tested here.

  ![dos_getcolor color dialog in AutoCAD 2027](docs/images/gui-getcolor.jpg)

The command-line results for these calls:

![Command-line results for the dialog tests](docs/images/gui-results.jpg)

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
