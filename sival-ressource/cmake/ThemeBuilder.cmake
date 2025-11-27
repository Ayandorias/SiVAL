# ==============================================================================
# Funktion: create_theme
#
# Beschreibung:
#   Generiert eine QSS-Datei aus einem Template, indem Platzhalter durch
#   definierte Farbwerte ersetzt werden. Optional können auch Icons
#   für das Theme generiert werden (SVG Color Replacement).
#
# Parameter:
#   NAME            - Der Name des Themes (wird Dateiname: <NAME>.qss)
#   THEME_ID        - (Optional) Interne ID für Ressourcenpfade (z.B. "light" in :/sival/light/...)
#                     Falls nicht gesetzt, wird NAME verwendet.
#
#   Farb-Parameter  - Entsprechen den @PLATZHALTER@ Namen im QSS Template:
#                     WINDOW_BG, CONTENT_BG, TEXT_PRIMARY, TEXT_SECONDARY,
#                     TEXT_DISABLED, BORDER_COLOR, DIVIDER_COLOR,
#                     HOVER_BG_CONTENT, HOVER_BG_NAV, HOVER_BG_ITEM,
#                     SELECTION_BG, SCROLL_TRACK, SCROLL_HANDLE,
#                     SECTION_BG, SECTION_HOVER, DESTRUCTIVE_COLOR, ACCENT_COLOR
#
#   ICONS           - (Optional) Liste von Icon-Dateinamen (.svg.in), die verarbeitet werden sollen.
#   ICON_COLOR      - (Optional) Die Farbe, die in die Icons injiziert wird.
#
# ==============================================================================

function(create_theme)

    # 1. Definition der erwarteten Argumente
    set(oneValueArgs
        NAME
        THEME_ID

        # Strukturfarben
        WINDOW_BG
        CONTENT_BG

        # Typografie
        TEXT_PRIMARY
        TEXT_SECONDARY
        TEXT_DISABLED

        # Ränder & Trenner
        BORDER_COLOR
        DIVIDER_COLOR

        # Interaktion / Hover
        HOVER_BG_CONTENT
        HOVER_BG_NAV
        HOVER_BG_ITEM
        SELECTION_BG

        # Scrollbars
        SCROLL_TRACK
        SCROLL_HANDLE

        # Sektionen
        SECTION_BG
        SECTION_HOVER

        # Spezial
        DESTRUCTIVE_COLOR
        ACCENT_COLOR

        # Icon Optionen
        ICON_COLOR
    )

    set(multiValueArgs ICONS) # Liste der Icons

    # 2. Argumente parsen (Prefix "THEME_" wird vorangestellt)
    cmake_parse_arguments(THEME "" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # 3. Validierung
    if(NOT THEME_NAME)
        message(FATAL_ERROR "create_theme: 'NAME' ist zwingend erforderlich!")
    endif()

    # Fallback für THEME_ID setzen, falls nicht explizit übergeben
    if(NOT THEME_THEME_ID)
        set(THEME_THEME_ID "${THEME_NAME}")
    endif()

    # 4. Variablen-Mapping für configure_file
    # (configure_file nutzt Variablen aus dem aktuellen Scope.
    #  Wir entfernen hier das "THEME_" Prefix für das Template.)

    set(THEME_ID          ${THEME_THEME_ID})

    set(WINDOW_BG         ${THEME_WINDOW_BG})
    set(CONTENT_BG        ${THEME_CONTENT_BG})
    set(TEXT_PRIMARY      ${THEME_TEXT_PRIMARY})
    set(TEXT_SECONDARY    ${THEME_TEXT_SECONDARY})
    set(TEXT_DISABLED     ${THEME_TEXT_DISABLED})
    set(BORDER_COLOR      ${THEME_BORDER_COLOR})
    set(DIVIDER_COLOR     ${THEME_DIVIDER_COLOR})
    set(HOVER_BG_CONTENT  ${THEME_HOVER_BG_CONTENT})
    set(HOVER_BG_NAV      ${THEME_HOVER_BG_NAV})
    set(HOVER_BG_ITEM     ${THEME_HOVER_BG_ITEM})
    set(SELECTION_BG      ${THEME_SELECTION_BG})
    set(SCROLL_TRACK      ${THEME_SCROLL_TRACK})
    set(SCROLL_HANDLE     ${THEME_SCROLL_HANDLE})
    set(SECTION_BG        ${THEME_SECTION_BG})
    set(SECTION_HOVER     ${THEME_SECTION_HOVER})
    set(DESTRUCTIVE_COLOR ${THEME_DESTRUCTIVE_COLOR})
    set(ACCENT_COLOR      ${THEME_ACCENT_COLOR})

    # 5. QSS Generierung

    # Pfad zum Template (Annahme: Liegt in resources/ neben dem Aufrufer)
    set(TEMPLATE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/res/template_theme.qss.in")

    # Zielpfad: Wir generieren in den Source-Tree unter "generated",
    # damit Qt Resources (.qrc) die Dateien finden kann.
    set(OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/")
    file(MAKE_DIRECTORY ${OUTPUT_DIR})

    set(QSS_OUTPUT_FILE "${OUTPUT_DIR}/${THEME_NAME}/${THEME_NAME}.qss")

    configure_file(
        "${TEMPLATE_FILE}"
        "${QSS_OUTPUT_FILE}"
        @ONLY
    )

    # 6. (Optional) Icon Generierung
    if(THEME_ICONS AND THEME_ICON_COLOR)

        # Zielordner für Icons dieses Themes (z.B. generated/light/icons)
        set(ICON_OUT_DIR "${OUTPUT_DIR}/${THEME_ID}")
        file(MAKE_DIRECTORY ${ICON_OUT_DIR})

        # Variable für das Icon-Template setzen
        set(ICON_FILL_COLOR ${THEME_ICON_COLOR})

        foreach(ICON_IN_FILE ${THEME_ICONS})
            # Dateinamen ohne .in Endung (z.B. "close.svg")
            string(REGEX REPLACE "\\.in$" "" ICON_NAME ${ICON_IN_FILE})

            set(ICON_TEMPLATE "${CMAKE_CURRENT_SOURCE_DIR}/res/icons/${ICON_IN_FILE}")
            set(ICON_OUTPUT   "${ICON_OUT_DIR}/${ICON_NAME}")

            message(STATUS ${ICON_TEMPLATE})
            configure_file(
                "${ICON_TEMPLATE}"
                "${ICON_OUTPUT}"
                @ONLY
            )
        endforeach()

        message(STATUS "SiVAL Theme '${THEME_NAME}': QSS und ${THEME_ICONS_LENGTH} Icons generiert.")
    else()
        message(STATUS "SiVAL Theme '${THEME_NAME}': QSS generiert.")
    endif()

endfunction()
