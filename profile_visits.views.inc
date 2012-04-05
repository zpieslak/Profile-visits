<?php

/**
 * @file
 * Contains views hooks functions.
 */

/**
 * Implements hook_views_data().
 */
function profile_visits_views_data() {
  $data['users_visits']['table']['group'] = t('Users visits');

  $data['users_visits']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid_host',
    ),
  );

  // Uid of profile being viewed.
  $data['users_visits']['uid_host'] = array(
    'title' => t('Uid of the host'),
    'help' => t('Host user.'),
    'relationship' => array(
      'base' => 'users',
      'field' => 'uid_host',
      'handler' => 'views_handler_relationship',
      'label' => t('Host uid'),
    ),
  );

  // Uid of the visitor.
  $data['users_visits']['uid_visitor'] = array(
    'title' => t('Uid of the visitor'),
    'help' => t('Visitor'),
    'relationship' => array(
      'base' => 'users',
      'field' => 'uid_visitor',
      'handler' => 'views_handler_relationship',
      'label' => t('Visitor uid'),
    ),
  );

  // True/false if user saw that his profile was visited.
  $data['users_visits']['host_read'] = array(
    'title' => t('Does host user knows about visit'),
    'help' => t('True or false.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Published'),
      'type' => 'yes-no',
      'use equal' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Date of visit.
  $data['users_visits']['visited_at'] = array(
    'title' => t('Visited date'),
    'help' => t('Last date of visit'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_pre_render().
 */
function profile_visits_views_pre_render(&$view) {
  if ($view->name == 'profile_visits') {
    global $user;

    // Check if there is any unread visit.
    if (!empty($view->result) && $view->args[0] == $user->uid) {
      $host_read = FALSE;

      foreach ($view->result as $item) {
        if ($item->users_visits_host_read == 0) {
          $host_read = TRUE;
          break;
        }
      }

      // If there is any unread visit update it, because user already knows
      // about it.
      if ($host_read == TRUE) {
        profile_visits_query_update_visit_read($user->uid, $host_read);

        // Clear cache.
        $cid = 'uid_host_count:' . $user->uid;
        cache_clear_all($cid, 'cache');
      }
    }
  }
}
