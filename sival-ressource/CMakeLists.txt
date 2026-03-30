cmake_minimum_required(VERSION 3.20)

project(sival-ressource LANGUAGES CXX)

# ==============================================================================
# 1. Theme-Builder Konfiguration
# ==============================================================================

# Das externe Modul für den ThemeBuilder laden
# (Es wird vorausgesetzt, dass ThemeBuilder.cmake im Unterordner "cmake/" liegt)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(ThemeBuilder)

# Liste der Icons definieren, die eingefärbt werden sollen (.svg.in)
# Diese müssen im Ordner "resources/icons/" liegen.
set(SIVAL_ICONS
    arrow-down.svg.in
    check.svg.in
    close.svg.in
    close_hover.svg.in
    cogwheel.svg.in
    enclosure.svg.in
    enclosure-fill.svg.in
    export.svg.in
    general.svg.in
    help.svg.in
    home.svg.in
    iconize.svg.in
    import.svg.in
    info.svg.in
    keyboard.svg.in
    max.svg.in
    min.svg.in
    minus.svg.in
    mouse.svg.in
    new.svg.in
    open.svg.in
    plus.svg.in
    print.svg.in
    projects.svg.in
    projects_close.svg.in
    project_properties.svg.in
    save.svg.in
    save_as.svg.in
    save_changes.svg.in
    speaker.svg.in
    copy.svg.in
    indeterminate.svg.in
    edit.svg.in
    trash.svg.in
    sealed.svg.in
    vented.svg.in
    warning.svg.in
    theme_dark.svg.in
    theme_light.svg.in
    download.svg.in
    music.svg.in
    camera.svg.in
    device-hdd.svg.in
    buildings.svg.in
    folder.svg.in
    speaker_new.svg.in
    enclosure_new.svg.in
    enclosure_sealed.svg.in
    enclosure_vented.svg.in
)

# ==============================================================================
# 2. Theme Generierung (Aufrufe)
# ==============================================================================

# --- Generiere LIGHT Theme ---
create_theme(
    NAME "light"

    WINDOW_BG         "#E5E5E8"
    DISABLED_BG       "#D5D5D8"
    CONTENT_BG        "#FFFFFF"
    ALTERNATE_BG      "#FCFCFF"

    TEXT_PRIMARY      "#6B6B6E"
    TEXT_SECONDARY    "#ABABAE"
    TEXT_DISABLED     "#888888"

    BORDER_COLOR      "#C5C5C8"
    DIVIDER_COLOR     "#E5E5E8"

    HOVER_BG_CONTENT  "#F0F0F3"
    HOVER_BG_NAV      "#DADADD"
    HOVER_BG_ITEM     "#F7F7F9"

    SELECTION_BG      "#0078D7"
    TEXT_SELECTION    "#FCFCFF"

    SCROLL_TRACK      "#B5B5B8"
    SCROLL_HANDLE     "#A5A5A8"

    SECTION_BG        "#E0E0E3"
    SECTION_HOVER     "#D5D5D8"

    DESTRUCTIVE_COLOR "#FF0000"
    ACCENT_COLOR      "#0078D7"

    BORDER_ACCEPT     "#22744a"
    BG_ACCEPT         "#a6d7be"
    BG_ACCEPT_HOVER   "#c4f2da"

    # Icon-Konfiguration für Light (Dunkle Icons auf hellem Grund)
    ICONS       ${SIVAL_ICONS}
    ICON_COLOR  "#6B6B6B"
)

# --- Generiere DARK Theme (SiVAL Standard) ---
create_theme(
    NAME "dark"

    # Palette (Angepasst an SiVAL Dark Logik: #1E1E1E / #2D2D30)
    WINDOW_BG         "#1E1E21"  # Navigationsbereich (Dunkler)
    DISABLED_BG       "#2E2E31"
    CONTENT_BG        "#2D2D30"  # Inhaltsbereich (Kühles Grau)
    ALTERNATE_BG      "#333336"

    TEXT_PRIMARY      "#CCCCCF"  # Helles Grau (nicht hartes Weiß)
    TEXT_SECONDARY    "#969699"
    TEXT_DISABLED     "#555558"

    BORDER_COLOR      "#3E3E42"  # Subtile Grenzen
    DIVIDER_COLOR     "#1E1E22"

    HOVER_BG_CONTENT  "#3E3E45"  # Hover im Inhalt
    HOVER_BG_NAV      "#252529"  # Hover in der Navigation
    HOVER_BG_ITEM     "#333336"

    SELECTION_BG      "#0078DA"  # Dunkles Blau für Selektionen
    TEXT_SELECTION    "#FCFCFF"

    SCROLL_TRACK      "#252529"
    SCROLL_HANDLE     "#424245"

    SECTION_BG        "#252529"
    SECTION_HOVER     "#2D2D30"

    DESTRUCTIVE_COLOR "#FF5558"  # Helleres Rot für Dark Mode
    ACCENT_COLOR      "#0078D7"  # Akzent bleibt gleich

    BORDER_ACCEPT     "#22744a"
    BG_ACCEPT         "#385344"
    BG_ACCEPT_HOVER   "#5d7a6a"

    # Icon-Konfiguration für Dark (Helle Icons)
    ICONS       ${SIVAL_ICONS}
    ICON_COLOR  "#CCCCCC"
)

# ==============================================================================
# 3. Bibliotheks-Definition
# ==============================================================================

# (Der Aufruf find_package(Qt6 ... LinguistTools) wurde entfernt,
#  da er bereits global durch die SiVAL-Suite erfolgt ist.)

# Eine statische oder shared Bibliothek nur für die Ressourcen
add_library(sival-ressource SHARED
    light_theme.qrc
    dark_theme.qrc
    sival-settings.qrc
    settings/default_settings.sival
    settings/speaker.sivalspkr
    settings/enclosure_sealed.sivalenc
    res/template_theme.qss.in
)

# Automatische Verarbeitung von Qt-Ressourcen (RCC) aktivieren
set_target_properties(sival-ressource PROPERTIES AUTORCC ON)

# Ressourcen brauchen Qt::Core
target_link_libraries(sival-ressource PUBLIC
    Qt::Core
)

# ==============================================================================
# 4. Übersetzungen (i18n)
# ==============================================================================

qt_add_translations(sival-ressource
    TS_FILES
        i18n/sival_de_DE.ts
        i18n/sival_en_EN.ts
    RESOURCE_PREFIX "/i18n"

    # Die Quellen werden aus allen relevanten Unterprojekten zusammengeführt
    # CMAKE_SOURCE_DIR verweist auf das Root-Verzeichnis (SiVAL-Suite)
    SOURCES
        "${CMAKE_SOURCE_DIR}/sival-core"
        "${CMAKE_SOURCE_DIR}/sival-gui"
        "${CMAKE_SOURCE_DIR}/sival-project"

        # Falls in sival-ressource selbst tr()-Texte existieren:
        "${CMAKE_CURRENT_SOURCE_DIR}"
)








# # Das externe Modul für den ThemeBuilder laden
# # (Annahme: ThemeBuilder.cmake liegt im Unterordner "cmake/")
# list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
# include(ThemeBuilder)

# # Liste der Icons definieren, die eingefärbt werden sollen (.svg.in)
# # Diese müssen im Ordner "resources/icons/" liegen.
# set(SIVAL_ICONS
#     arrow-down.svg.in
#     check.svg.in
#     close.svg.in
#     close_hover.svg.in
#     cogwheel.svg.in
#     enclosure.svg.in
#     enclosure-fill.svg.in
#     export.svg.in
#     general.svg.in
#     help.svg.in
#     home.svg.in
#     iconize.svg.in
#     import.svg.in
#     info.svg.in
#     keyboard.svg.in
#     max.svg.in
#     min.svg.in
#     minus.svg.in
#     mouse.svg.in
#     new.svg.in
#     open.svg.in
#     plus.svg.in
#     print.svg.in
#     projects.svg.in
#     project_properties.svg.in
#     save.svg.in
#     save_as.svg.in
#     speaker.svg.in
#     copy.svg.in
#     indeterminate.svg.in
#     edit.svg.in
#     trash.svg.in
#     sealed.svg.in
#     vented.svg.in
#     warning.svg.in
#     theme_dark.svg.in
#     theme_light.svg.in
# )

# # ==============================================================================
# # 2. Theme Generierung (Aufrufe)
# # ==============================================================================

# # --- Generiere LIGHT Theme ---
# create_theme(
#     NAME "light"

#     WINDOW_BG         "#E5E5E8"
#     DISABLED_BG       "#D5D5D8"
#     CONTENT_BG        "#FFFFFF"
#     ALTERNATE_BG      "#FCFCFF"

#     TEXT_PRIMARY      "#6B6B6E"
#     TEXT_SECONDARY    "#ABABAE"
#     TEXT_DISABLED     "#888888"

#     BORDER_COLOR      "#C5C5C8"
#     DIVIDER_COLOR     "#E5E5E8"

#     HOVER_BG_CONTENT  "#F0F0F3"
#     HOVER_BG_NAV      "#DADADD"
#     HOVER_BG_ITEM     "#FCFCFF"

#     SELECTION_BG      "#0078D7"
#     TEXT_SELECTION    "#FCFCFF"

#     SCROLL_TRACK      "#B5B5B8"
#     SCROLL_HANDLE     "#A5A5A8"

#     SECTION_BG        "#E0E0E3"
#     SECTION_HOVER     "#D5D5D8"

#     DESTRUCTIVE_COLOR "#FF0000"
#     ACCENT_COLOR      "#0078D7"

#     BORDER_ACCEPT     "#22744a"
#     BG_ACCEPT         "#a6d7be"
#     BG_ACCEPT_HOVER   "#c4f2da"

#     Icon-Konfiguration für Light (Dunkle Icons auf hellem Grund)
#     ICONS      ${SIVAL_ICONS}
#     ICON_COLOR "#6B6B6B"
# )

# # --- Generiere DARK Theme (SiVAL Standard) ---
# create_theme(
#     NAME "dark"

#     # Palette (Angepasst an SiVAL Dark Logik: #1E1E1E / #2D2D30)
#     WINDOW_BG         "#1E1E21"  # Navigationsbereich (Dunkler)
#     DISABLED_BG       "#2E2E31"
#     CONTENT_BG        "#2D2D30"  # Inhaltsbereich (Kühles Grau)
#     ALTERNATE_BG      "#333336"

#     TEXT_PRIMARY      "#CCCCCF"  # Helles Grau (nicht hartes Weiß)
#     TEXT_SECONDARY    "#969699"
#     TEXT_DISABLED     "#555558"

#     BORDER_COLOR      "#3E3E42"  # Subtile Grenzen
#     DIVIDER_COLOR     "#1E1E22"

#     HOVER_BG_CONTENT  "#3E3E45"  # Hover im Inhalt
#     HOVER_BG_NAV      "#252529"  # Hover in der Navigation
#     HOVER_BG_ITEM     "#333336"

#     SELECTION_BG      "#0078DA"  # Dunkles Blau für Selektionen
#     TEXT_SELECTION    "#FCFCFF"

#     SCROLL_TRACK      "#252529"
#     SCROLL_HANDLE     "#424245"

#     SECTION_BG        "#252529"
#     SECTION_HOVER     "#2D2D30"

#     DESTRUCTIVE_COLOR "#FF5558"  # Helleres Rot für Dark Mode
#     ACCENT_COLOR      "#0078D7"  # Akzent bleibt gleich

#     BORDER_ACCEPT     "#22744a"
#     BG_ACCEPT         "#385344"
#     BG_ACCEPT_HOVER   "#5d7a6a"

#     Icon-Konfiguration für Dark (Helle Icons)
#     ICONS      ${SIVAL_ICONS}
#     ICON_COLOR "#CCCCCC"
# )


# find_package(Qt6 REQUIRED COMPONENTS LinguistTools)


# # Eine statische Bibliothek nur für die Ressourcen
# add_library(sival-ressource SHARED
#     light_theme.qrc
#     dark_theme.qrc
#     sival-settings.qrc
#     settings/default_settings.sival
#     res/template_theme.qss.in
# )

# qt_add_translations(sival-ressource
#     TS_FILES
#         i18n/sival_de_DE.ts
#         i18n/sival_en_EN.ts
#     RESOURCE_PREFIX "/i18n"

#     # Die Quellen werden aus allen relevanten Unterprojekten zusammengeführt
#     SOURCES
#         "${CMAKE_SOURCE_DIR}/sival-core"
#         "${CMAKE_SOURCE_DIR}/sival-gui"
#         "${CMAKE_SOURCE_DIR}/sival-project"
#         # Falls in sival-ressource selbst tr()-Texte existieren:
#         "${CMAKE_CURRENT_SOURCE_DIR}"
# )

# # Ressourcen brauchen Qt::Core
# target_link_libraries(sival-ressource PUBLIC
#     Qt::Core
# )
