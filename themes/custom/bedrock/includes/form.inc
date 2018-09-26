<?php

/**
 * @file
 * Preprocess form functions.
 */

use Drupal\Core\Form\FormStateInterface;

/**
 * Implements hook_theme_suggestions_HOOK_alter() for form templates.
 */
function bedrock_theme_suggestions_form_alter(array &$suggestions, array $variables) {
  $element = $variables['element'];

  // Add per form theme hook suggestion.
  $suggestions[] = 'form__' . $element['#form_id'];
  $suggestions[] = 'form__' . bedrock_suggestion_safe($element['#id']);
}

/**
 * Implements hook_theme_suggestions_HOOK_alter() for container templates.
 */
function bedrock_theme_suggestions_container_alter(array &$suggestions, array $variables) {
  $element = $variables['element'];

  if (isset($element['#type'])) {
    // Add per type theme hook suggestion.
    $suggestions[] = 'container__' . $element['#type'];
  }
}

/**
 * Implements hook_theme_suggestions_HOOK_alter() for form element templates.
 */
function bedrock_theme_suggestions_form_element_alter(array &$suggestions, array $variables) {
  $element = $variables['element'];

  // Add per type theme hook suggestion.
  $suggestions[] = 'form_element__' . $element['#type'];

  if (isset($element['#name'])) {
    $suggestions[] = 'form_element__' . $element['#type'] . '__' . $element['#name'];
  }

  if (isset($element["#name"])) {
    $suggestions[] = 'form_element__' . $element['#type'] . '__' . $element["#name"];
  }
}

/**
 * Implements hook_theme_suggestions_HOOK_alter() for form input templates.
 */
function bedrock_theme_suggestions_input_alter(array &$suggestions, array $variables) {
  $element = $variables['element'];

  $suggestions[] = 'input__' . $element['#type'] . '__' . $element['#name'];
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function bedrock_theme_suggestions_select_alter(array &$suggestions, array $variables) {
  $element = $variables['element'];

  if (isset($element["#name"])) {
    $suggestions[] = $element['#type'] . '__' . $element["#name"];
  }
}
